// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"

#include "Chunk.h"
#include "FastNoiseLite.h"
#include "Kismet/KismetSystemLibrary.h"

DECLARE_STATS_GROUP(TEXT("PerformanceStats"), STATGROUP_PerfStats, STATCAT)
DECLARE_CYCLE_STAT(TEXT("GenTime"), GENTIME, STATGROUP_PerfStats)

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
	SCOPE_CYCLE_COUNTER(GENTIME);
	Super::BeginPlay();
	double Time = GetWorld()->GetTimeSeconds();
	Noise->SetFrequency(Frequency);
	Noise->SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	Noise->SetFractalType(FastNoiseLite::FractalType_FBm);
	TArray<FTask> Tasks;
	TArray<AChunk*> Chunks;
	for (int x = -DrawDistance; x <= DrawDistance; ++x)
	{
		for (int y = -DrawDistance; y <= DrawDistance; ++y)
		{
			AChunk* CurrentChunk = GetWorld()->SpawnActor<AChunk>(Chunk, FVector(x * ChunkSize * 100, y * ChunkSize * 100, 0), FRotator::ZeroRotator);
			CurrentChunk->SetNoise(Noise);
			Tasks.Add(UE::Tasks::Launch(UE_SOURCE_LOCATION, [CurrentChunk]{CurrentChunk->Generate();}));
			Chunks.Add(CurrentChunk);
		}
	}
	UE::Tasks::Wait(Tasks);
	for (int i = 0; i < Chunks.Num(); ++i)
	{
		Chunks[i]->ApplyMesh();
	}
	
	UKismetSystemLibrary::PrintText(GetWorld(), FText::FromString(FString::Printf(TEXT("World %f"), GetWorld()->GetTimeSeconds() - Time)));
}


