// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/WorldSettings.h"
#include "ChunkWorld.generated.h"

class AChunk;
class FastNoiseLite;

UCLASS()
class VOXELTERRAINGENERATOR_API AChunkWorld : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChunkWorld();
	
	UPROPERTY(EditAnywhere, Category = "Voxel World")
	TSubclassOf<AActor> Chunk;
	
	UPROPERTY(EditAnywhere, Category = "Voxel World")
	TArray<TSubclassOf<AChunk>> BiomeChunks;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Voxel World")
	int DrawDistance = 5;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Voxel World")
	int ChunkSize = 32;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	float TerrainSeed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	float Frequency = 0.005f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	float BiomeFrequency = 0.005f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	int ChunksGeneratedPerFrame = 100;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	float RenderDistance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Chunk")
	float PreLoadDistance = 5;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaTime ) override;
	
	void CheckNeighbours(TObjectPtr<AChunk> CurrentChunk);
	
	void PreLoadInDistance(int distance);
	
	int GetBiomeType(FVector2D Coords);
	
	int GetNeighbourBiome(int OwnBiomeType, float x, float y);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "ChunkWorld")
	void FinishedGenerating();
	
private:
	TObjectPtr<FastNoiseLite> Noise;
	
	TObjectPtr<FastNoiseLite> BiomeNoise;
	
	TArray<TArray<TObjectPtr<AChunk>>> Chunks;
	
	TArray<TObjectPtr<AChunk>> UnLoadedChunks;
	
	TArray<TObjectPtr<AChunk>> LoadedChunks;
	
	float MeshGenTimer = 0.f;
	
	UPROPERTY()
	APawn* Player;

};
