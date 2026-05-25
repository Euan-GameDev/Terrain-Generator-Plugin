// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"

#include "Chunk.h"
#include "FastNoiseLite.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

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
}

// Called when the game starts or when spawned
void AChunkWorld::BeginPlay()
{
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SCOPE_CYCLE_COUNTER(GENPREP);
	MeshGenTimer = GetWorld()->GetTimeSeconds();
	Super::BeginPlay();
	Noise->SetFrequency(Frequency);
	Noise->SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	Noise->SetFractalType(FastNoiseLite::FractalType_FBm);
	TArray<FTask> Tasks;
	for (int x = -DrawDistance; x < DrawDistance; ++x)
	{
		for (int y = -DrawDistance; y < DrawDistance; ++y)
		{
			AChunk* CurrentChunk = GetWorld()->SpawnActor<AChunk>(Chunk, FVector(x * ChunkSize * 100, y * ChunkSize * 100, 0), FRotator::ZeroRotator);
			CurrentChunk->SetNoise(Noise);
			CurrentChunk->ChunkCoords = {static_cast<double>(x), static_cast<double>(y)};
			Tasks.Add(UE::Tasks::Launch(UE_SOURCE_LOCATION, [CurrentChunk]{CurrentChunk->Generate();}));
			Chunks.Add(CurrentChunk);
		}
	}
	UE::Tasks::Wait(Tasks);
	//for (int i = 0; i < Chunks.Num(); ++i)
	//{
	//	Chunks[i]->ApplyMesh();
	//}
}

void AChunkWorld::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(GENMESH);
	for (int i = 0; i < Chunks.Num(); i++)
	{
		//TArray<FVector2D> ChunksNeighbours = LoadedChunks[i]->GetNeighbours();
		//for (int j = 0; j < ChunksNeighbours.Num(); j++)
		
		// If we are in range of the chunk and it's not already loaded add it to list of unloaded chunks that we need to load
		if (Chunks[i]->GetDistanceTo(Player) < RenderDistance * ChunkSize * 100)
		{
			if (!LoadedChunks.Contains(Chunks[i]))
			{
				UnLoadedChunks.Add(Chunks[i]);
			}
		}
		// if we aren't in range of the chunk and it should be loaded then unload it and remove it from the loaded array
		else
		{
			if (LoadedChunks.Contains(Chunks[i]))
			{
				Chunks[i]->DisableMesh();
				LoadedChunks.Remove(Chunks[i]);
			}
		}
	}
	
	if (!UnLoadedChunks.IsEmpty())
	{
		// for each of the unloaded chunks we need to load
		for (int i = 0; i < UnLoadedChunks.Num(); i++)
		{
			if (!UnLoadedChunks.IsEmpty())
			{
				UnLoadedChunks[0]->ApplyMesh();
				LoadedChunks.Add(UnLoadedChunks[0]);
				UnLoadedChunks.RemoveAt(0);
				UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Still Generating chunks left: %i"), UnLoadedChunks.Num()));
			}
		}
	}
	else
	{
		if (FinishedGenerating == false)
		{
			UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Time To Generate Mesh %f"), GetWorld()->GetTimeSeconds() - MeshGenTimer));
			FinishedGenerating = true; 
		}
	}
	
	
}


