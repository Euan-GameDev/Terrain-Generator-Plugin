// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "ChunkNeighbour.h"
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Chunk.generated.h"

enum class EDirection;
class UProceduralMeshComponent;
class FastNoiseLite;

UCLASS()
class PROCGEN_API AChunk : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Generate();
	
	void SetNoise(TObjectPtr<FastNoiseLite> ChunkNoise);
	
	/**
    * Pass the mesh data (index and vertex data) into the ProceduralMesh for rendering
    */
	void ApplyMesh();
	
	void DisableMesh();
	
	TArray<FVector2D> GetNeighbours();
	
	void ApplyBiomeEffects(AChunk* Biome);
	
	void AddNeighbourBiome(FChunkNeighbour Biome);
	
private:
	/**
	 * Populate the Blocks array according to our heightmap
	 */
	void GenerateBlocks();
	
	/**
	 * Populate VertexData array based on the blocks
	 */
	void GenerateMesh();
	
	/**
	 * 
	 * @param Position Position of the block to check
	 * @return Returns true if the position contains a transparent block (air)
	 */
	bool Check(FVector Position) const;
	
	/**
	 * Creates a new face and adds the vertex and index data of that face to the corresponding arrays
	 * @param Direction Direction for the face to generate
	 * @param Position Position for the face to generate
	 */
	void CreateFace(EDirection Direction, FVector Position, FBlock BlockType);
	
	/**
	 * 
	 * @param Direction Direction of the face
	 * @param Position Position of the face
	 * @return Vertex data of the 4 corners of the face of the given position and direction based on the vertex look up table (BlockVertexData)
	 */
	TArray<FVector> GetFaceVertices(EDirection Direction, FVector Position) const;
	
	/**
	 * 
	 * @param Direction Direction from position
	 * @param Position Original Position
	 * @return Adjacent position in the given direction from the original position
	 */
	FVector GetPositionInDirection(EDirection Direction, FVector Position) const;
	
	
	/**
	 * 
	 * @param X X Coordinate of block
	 * @param Y Y Coordinate of block
	 * @param Z Z Coordinate of block
	 * @return Index of the block at xyz location in the Blocks array
	 */
	int GetBlockIndex(int X, int Y, int Z) const;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @return The height at the entered location
	 */
	int GetHeightAtLocation(float x, float y, float xProgress, float yProgress);
	
	FBlock GetBlockType(EBlockType layer) const;
	
	void AddBlockLayerToArray(TArray<FBlock>& Blocks);
	
	void GenerateContainers();
	
public:
	UPROPERTY(EditAnywhere, Category = "Chunk")
	int Size = 32;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	int Scale = 1;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	float RedistributionPow = 1.f;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	int Octaves = 3;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	float HeightScalar;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	TArray<FBlock> UnderGroundBlocks;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	TArray<FBlock> SubSurfaceBlocks;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	TArray<FBlock> SurfaceBlocks;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	TArray<FBlock> AirBlocks;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	TArray<FBlock> MountainBlocks;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	bool GenerateCollision = false;
	
	UPROPERTY(EditAnywhere, Category = "Chunk")
	bool EnableShadows = false;
	
	UPROPERTY(VisibleAnywhere, Category = "Chunk")
	FVector2D ChunkCoords = {0, 0};
	
	UPROPERTY(VisibleAnywhere, Category = "Chunk")
	TArray<FChunkNeighbour> ChunkNeighbours;

private:
	UPROPERTY()
	TObjectPtr<UProceduralMeshComponent> Mesh;
	
	TArray<FBlock*> BlockTypes;
	TArray<FBlock> Blocks;
	TObjectPtr<FastNoiseLite> Noise;
	
	TArray<TArray<FVector>> VertexNormals;
	TArray<TArray<FVector>> VertexData;
	TArray<TArray<FColor>> VertexColors;
	TArray<TArray<int>> TriangleData;
	TArray<TArray<FVector2D>> UVData;
	TArray<TArray<FProcMeshTangent>> TangentData;
	
	TArray<int> VertexCount;
	
	const FVector BlockVertexData[8] = 
	{
		FVector(100, 100, 100),
		FVector(100, 0, 100),
		FVector(100, 0, 0),
		FVector(100, 100, 0),
		FVector(0, 0, 100),
		FVector(0, 100, 100),
		FVector(0, 100, 0),
		FVector(0, 0, 0)
	};
	
	const int BlockTriangleData[24] =
	{
		0,1,2,3, // Forward
		5,0,3,6, // Right
		4,5,6,7, // Back
		1,4,7,2, // Left
		5,4,1,0, // Up
		3,2,7,6, // Down
	};
	
	const FVector DirectionVectors[8] = 
	{
		FVector(1, 0, 0), // Forward
		FVector(0, 1, 0), // Right
		FVector(-1, 0, 0), // Back
		FVector(0, -1, 0), // Left
		FVector(0, 0, 1), // Up
		FVector(0, 0, -1), // Down
	};
};
