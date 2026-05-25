// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChunkWorld.generated.h"

class AChunk;
class FastNoiseLite;
UCLASS()
class PROCGEN_API AChunkWorld : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChunkWorld();
	
	UPROPERTY(EditAnywhere, Category = "Voxel World")
	TSubclassOf<AActor> Chunk;
	
	UPROPERTY(EditAnywhere, Category = "Voxel World")
	int DrawDistance = 5;
	
	UPROPERTY(EditAnywhere, Category = "Voxel World")
	int ChunkSize = 32;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	int Octaves = 3;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	float Frequency = 0.005f;

	UPROPERTY(EditAnywhere, Category = "Chunk")
	int ChunksGeneratedPerFrame = 100;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	float RenderDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;
	
private:
	TObjectPtr<FastNoiseLite> Noise;
	
	TArray<TObjectPtr<AChunk>> Chunks;
	
	TArray<TObjectPtr<AChunk>> UnLoadedChunks;
	
	TArray<TObjectPtr<AChunk>> LoadedChunks;
	
	float MeshGenTimer = 0.f;
	
	bool FinishedGenerating = false;
	
	UPROPERTY()
	AActor* Player;

};
