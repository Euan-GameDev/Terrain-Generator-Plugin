// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"
#include "Chunk.h"
#include "ChunkNeighbour.h"
#include "FastNoiseLite.h"
#include "CoreMinimal.h"
#include "PoissonNoise.h"
#include "Kismet/GameplayStatics.h"

DECLARE_STATS_GROUP(TEXT("PerformanceStats"), STATGROUP_PerfStats, STATCAT)
DECLARE_CYCLE_STAT(TEXT("GenPrep"), GENPREP, STATGROUP_PerfStats)
DECLARE_CYCLE_STAT(TEXT("GenMesh"), GENMESH, STATGROUP_PerfStats)

using UE::Tasks::FTask;

// Sets default values
AChunkWorld::AChunkWorld()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Noise = new FastNoiseLite();
	BiomeNoise = new FastNoiseLite();
	TreeNoise = new PoissonNoise();
}

// Called when the game starts or when spawned
void AChunkWorld::BeginPlay()
{
	StartedGenerating();
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SCOPE_CYCLE_COUNTER(GENPREP);
	MeshGenTimer = GetWorld()->GetTimeSeconds();
	Super::BeginPlay();
	Noise->SetFrequency(Frequency);
	Noise->SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	Noise->SetFractalType(FastNoiseLite::FractalType_FBm);
	Noise->SetSeed(TerrainSeed);
	
	BiomeNoise->SetNoiseType(FastNoiseLite::NoiseType_Cellular);
	BiomeNoise->SetFrequency(BiomeFrequency);
	BiomeNoise->SetCellularReturnType(FastNoiseLite::CellularReturnType_CellValue);
	BiomeNoise->SetSeed(TerrainSeed);
	
	TreeNoise->Width = DrawDistance * 200 * ChunkSize;
	TreeNoise->Height = DrawDistance * 200 * ChunkSize;
	TreeNoise->MinDistance = 5000;
	TreeNoise->GenerateNoise();
	
	
	TArray<FTask> Tasks;
	for (int x = -DrawDistance; x < DrawDistance; ++x)
	{
		TArray<TObjectPtr<AChunk>> CurrentArray;
		for (int y = -DrawDistance; y < DrawDistance; ++y)
		{
			int BiomeTypeIndex = GetBiomeType({static_cast<double>(x + DrawDistance), static_cast<double>(y + DrawDistance)});
			TSubclassOf<AActor> ChunkType = BiomeChunks[BiomeTypeIndex];
			AChunk* CurrentChunk = GetWorld()->SpawnActor<AChunk>(ChunkType, FVector(x * ChunkSize * 100, y * ChunkSize * 100, 0), FRotator::ZeroRotator);
			CurrentChunk->SetNoise(Noise);
			CurrentChunk->SetTreeNoise(TreeNoise);
			CurrentChunk->ChunkCoords = {static_cast<double>(x + DrawDistance), static_cast<double>(y + DrawDistance)};
			CurrentChunk->SetSize(ChunkSize);
			for (int i = 0; i < CurrentChunk->GetNeighbours().Num(); i++)
			{
				int Type = GetBiomeType(CurrentChunk->GetNeighbours()[i]);
				AChunk* DefaultChunk = BiomeChunks[Type]->GetDefaultObject<AChunk>();
				CurrentChunk->AddNeighbourBiome({CurrentChunk->GetNeighbours()[i] - CurrentChunk->ChunkCoords, DefaultChunk->RedistributionPow, DefaultChunk->HeightScalar, DefaultChunk->Octaves});
			}
			
			
			Tasks.Add(UE::Tasks::Launch(UE_SOURCE_LOCATION, [CurrentChunk]{CurrentChunk->Generate();}));
			CurrentArray.Add(CurrentChunk);
		}
		Chunks.Add(CurrentArray);
	}
	UE::Tasks::Wait(Tasks);
	
	// Load the chunk at the middle of the world instantly
	PreLoadInDistance(PreLoadDistance);
	FinishedGenerating();
}

void AChunkWorld::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(GENMESH);
	
	if (!UnLoadedChunks.IsEmpty())
	{
		// for each of the unloaded chunks we need to load
		for (int i = 0; i < ChunksGeneratedPerFrame; i++)
		{
			if (!UnLoadedChunks.IsEmpty())
			{
				UnLoadedChunks[0]->ApplyMesh();
				LoadedChunks.Add(UnLoadedChunks[0]);
				UnLoadedChunks.RemoveAt(0);
			}
		}
	}
	
	// For every chunk that is loaded currently
	for (int i = 0; i < LoadedChunks.Num(); i++)
	{
		// If we are in range of the chunk and it's not already loaded add it to list of unloaded chunks that we need to load
		if (LoadedChunks[i]->GetDistanceTo(Player) < RenderDistance * ChunkSize * 100)
		{
			CheckNeighbours(LoadedChunks[i]);
		}
		// if we aren't in range of the chunk and it should be loaded then unload it and remove it from the loaded array
		else
		{
			LoadedChunks[i]->DisableMesh();
			LoadedChunks.RemoveAt(i);
			//UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Removed Chunk from loaded Chunks remaining: %i"), LoadedChunks.Num()));
		}
	}
}


void AChunkWorld::CheckNeighbours(TObjectPtr<AChunk> CurrentChunk)
{
	// Get the chunks neighbours
	TArray<FVector2D> ChunksNeighbours = CurrentChunk->GetNeighbours();
	for (int i = 0; i < ChunksNeighbours.Num(); i++)
	{
		int x = ChunksNeighbours[i].X;
		int y = ChunksNeighbours[i].Y;
		if (FMath::Abs(x) >= DrawDistance * 2 || FMath::Abs(y) >= DrawDistance * 2 || y < 0 || x < 0)
		{
			continue;
		}
		// If we are in range of the chunk and it's not already loaded add it to list of unloaded chunks that we need to load
		if (Chunks[x][y]->GetDistanceTo(Player) < RenderDistance * ChunkSize * 100)
		{
			if (!LoadedChunks.Contains(Chunks[x][y]) && !UnLoadedChunks.Contains(Chunks[x][y]))
			{
				UnLoadedChunks.Add(Chunks[x][y]);
				CheckNeighbours(Chunks[x][y]);
			}
		}
	}
}

void AChunkWorld::PreLoadInDistance(int distance)
{
	distance = FMath::Min(distance, DrawDistance);
	for (int x = -distance; x < distance; x++)
	{
		for (int y = -distance; y < distance; y++)
		{
			Chunks[x + DrawDistance][y + DrawDistance]->ApplyMesh();
			LoadedChunks.Add(Chunks[x + DrawDistance][y + DrawDistance]);
		}
	}
}

int AChunkWorld::GetBiomeType(FVector2D Coords)
{
	float RangePerBiome = 1.f / BiomeChunks.Num();
	float NoiseValue = (BiomeNoise->GetNoise(Coords.X, Coords.Y) + 1.f) / 2.f;
	for (int i = 0; i < BiomeChunks.Num(); i++)
	{
		if (NoiseValue <= (i + 1.f) * RangePerBiome)
		{
			return i;
		}
	}
	return 0;
}

int AChunkWorld::GetNeighbourBiome(int OwnBiomeType, float x, float y)
{
	float RangePerBiome = 1.f / BiomeChunks.Num();
	TArray<float> NeighbourNoiseValues;
	NeighbourNoiseValues.Add((BiomeNoise->GetNoise(x + 1, y) + 1.f) / 2.f);
	NeighbourNoiseValues.Add((BiomeNoise->GetNoise(x - 1, y) + 1.f) / 2.f);
	NeighbourNoiseValues.Add((BiomeNoise->GetNoise(x, y + 1) + 1.f) / 2.f);
	NeighbourNoiseValues.Add((BiomeNoise->GetNoise(x, y - 1) + 1.f) / 2.f);
	for (int i = 0; i < NeighbourNoiseValues.Num(); i++)
	{
		for (int j = 0; j < BiomeChunks.Num(); j++)
		{
			if (NeighbourNoiseValues[i] <= (j + 1.f) * RangePerBiome)
			{
				if (j != OwnBiomeType)
				{
					return j;
				}
				break;
			}
		}
	}
	
	return -1;
}


