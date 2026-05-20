// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"

#include "Chunk.h"
#include "FastNoiseLite.h"
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
			Tasks.Add(UE::Tasks::Launch(UE_SOURCE_LOCATION, [CurrentChunk]{CurrentChunk->Generate();}));
			Chunks.Add(CurrentChunk);
		}
	}
	UE::Tasks::Wait(Tasks);
	UnGeneratedChunks = Chunks;
	//for (int i = 0; i < Chunks.Num(); ++i)
	//{
	//	Chunks[i]->ApplyMesh();
	//}
}

void AChunkWorld::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(GENMESH);
	if (!UnGeneratedChunks.IsEmpty())
	{
		for (int i = 0; i < ChunksGeneratedPerFrame; i++)
		{
			if (!UnGeneratedChunks.IsEmpty())
			{
				UnGeneratedChunks[UnGeneratedChunks.Num() / 2]->ApplyMesh();
				UnGeneratedChunks.RemoveAt(UnGeneratedChunks.Num() / 2);
				UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Still generating"));
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


