// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcGen/Public/Chunk.h"
#include "ProceduralMeshComponent.h"
#include "FastNoiseLite.h"
#include "Block.h"

#include "Enums.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AChunk::AChunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>("Mesh");
	Mesh->CastShadow = true;
	
	Blocks.SetNum(Size * Size * Size);
	
	// Manually Setting Blocks for testing purposes
	Block Stone;
	Block Air;
	Stone.Type = EBlockType::Stone;
	Stone.Probability = 1.f;
	Air.Type = EBlockType::Air;
	Air.Probability = 9.f;
	
	UnderGroundBlocks.Emplace(Stone);
	UnderGroundBlocks.Emplace(Air);
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	
	
	//Generate();
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChunk::Generate()
{
	GenerateBlocks();
	
	GenerateMesh();
	
	ApplyMesh();
}

void AChunk::SetNoise(TObjectPtr<FastNoiseLite> ChunkNoise)
{
	Noise = ChunkNoise;
}

void AChunk::GenerateBlocks()
{
	const FVector Location = GetActorLocation();
	
	for (int x = 0; x < Size; ++x)
	{
		for (int y = 0; y < Size; ++y)
		{
			const float XPos = (x * 100 + Location.X) / 100;
			const float YPos = (y * 100 + Location.Y) / 100;
			
			const int Height = GetHeightAtLocation(XPos, YPos);
			
			
			// Everything at height or below will be stone for now
			for (int z = 0; z <= Height; ++z)
			{
				Blocks[GetBlockIndex(x, y, z)] = GetBlockType(x,y,z);
			}
			// Everything above the height will be air
			for (int z = Height; z < Size; ++z)
			{
				Blocks[GetBlockIndex(x, y, z)] = EBlockType::Air;
			}
			Blocks[GetBlockIndex(x, y, Height)] = EBlockType::Dirt;
		}
	}
}

void AChunk::GenerateMesh()
{
	for (int x = 0; x < Size; ++x)
	{
		for (int y = 0; y < Size; ++y)
		{
			for (int z = 0; z < Size; ++z)
			{
				if (Blocks[GetBlockIndex(x, y, z)] != EBlockType::Air)
				{
					const auto Position = FVector(x, y, z);
					
					for (auto Direction : {EDirection::Forward, EDirection::Right, EDirection::Back, EDirection::Left, EDirection::Up, EDirection::Down})
					{
						if (Check(GetPositionInDirection(Direction, Position)))
						{
							CreateFace(Direction, Position * 100);
						}
					}
				}
			}
		}
	}
}

void AChunk::ApplyMesh() const
{
	// TODO We aren't generating normals, colors or tangents at the moment
	// Not currently creating collision
	Mesh->CreateMeshSection(0, VertexData, TriangleData, VertexNormals, UVData, 
				VertexColors, TArray<FProcMeshTangent>(), false);
	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("VertexColorSize = {%i}"), VertexColors.Num()));
	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("VertexDataSize = {%i}"), VertexData.Num()));
	//UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf());
}

bool AChunk::Check(FVector Position) const
{
	// Checks if the position is outside the chunk returns true if it is
	// NOTE
	// We want to return true if the block is outside the chunk so that we will generate faces on the edges of the chunk.
	if (Position.X >= Size || Position.Y >= Size || Position.Z >= Size || Position.X < 0 || Position.Y < 0 || Position.Z < 0)
	{
		return true;
	}
	
	return Blocks[GetBlockIndex(Position.X, Position.Y, Position.Z)] == EBlockType::Air;
}

void AChunk::CreateFace(EDirection Direction, FVector Position)
{
	VertexData.Append(GetFaceVertices(Direction, Position));
	VertexColors.Add({0, 255, 0});
	VertexColors.Add({0, 255, 0});
	VertexColors.Add({0, 255, 0});
	VertexColors.Add({0, 255, 0});
	// UVData section is temporary until we add textures
	VertexNormals.Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals.Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals.Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals.Add(DirectionVectors[static_cast<int>(Direction)]);
	UVData.Append({FVector2D(1, 1), FVector2D(1, 0), FVector2D(0, 0), FVector2D(0, 1)});
	TriangleData.Append({VertexCount + 3, VertexCount + 2, VertexCount, VertexCount + 2, VertexCount + 1, VertexCount});
	VertexCount += 4;
}

TArray<FVector> AChunk::GetFaceVertices(EDirection Direction, FVector Position) const
{
	TArray<FVector> Vertices;
	
	for (int i = 0; i < 4; i++)
	{
		Vertices.Add(BlockVertexData[BlockTriangleData[i + static_cast<int>(Direction) * 4]] * Scale + Position);
	}
	
	return Vertices;
}

FVector AChunk::GetPositionInDirection(EDirection Direction, FVector Position) const
{
	return Position + DirectionVectors[static_cast<int>(Direction)];
}

int AChunk::GetBlockIndex(int X, int Y, int Z) const
{
	return Z * Size * Size + Y * Size + X;
}

int AChunk::GetHeightAtLocation(float x, float y)
{
	float Total = 0.f;
	float ScalarTotal = 0.f;
	for (int i = 1; i <= Octaves; ++i)
	{
		float Scalar = FMath::Pow(2.f, i - 1.f);
		ScalarTotal += 1.f / Scalar;
		Total += 1.f / Scalar * ((Noise->GetNoise(Scalar * x, Scalar * y) + 1.f) / 2.f);
	}
	return FMath::Clamp((FMath::Pow(Total / ScalarTotal * 1.2, RedistributionPow)) * (Size / 2.f), 1, Size);
}

EBlockType AChunk::GetBlockType(int X, int Y, int Z) const
{
	// Count up the total probability score of all the blocks
	float totalProb = 0.f;
	for (int i = 0; i < UnderGroundBlocks.Num(); ++i)
	{
		totalProb += UnderGroundBlocks[i].Probability;
	}
	// Get a random number between 0 and the total probability score
	float Roll = FMath::RandRange(0.0f, totalProb);
	for (int i = 0; i < UnderGroundBlocks.Num(); ++i)
	{
		Roll -= UnderGroundBlocks[i].Probability;
		if (Roll <= 0.f)
		{
			return UnderGroundBlocks[i].Type;
		}
	}
	
	return EBlockType::Stone;
}

