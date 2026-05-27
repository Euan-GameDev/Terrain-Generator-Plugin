// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcGen/Public/Chunk.h"
#include "ProceduralMeshComponent.h"
#include "FastNoiseLite.h"
#include "Block.h"
#include "ChunkNeighbour.h"

#include "Enums.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ProceduralMeshComponent/Public/KismetProceduralMeshLibrary.h"


using namespace UE::Tasks;
// Sets default values
AChunk::AChunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Blocks.SetNum(Size * Size * Size);
	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>("Mesh");
	Mesh->CastShadow = EnableShadows;
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	
	AddBlockLayerToArray(AirBlocks);
	AddBlockLayerToArray(SurfaceBlocks);
	AddBlockLayerToArray(SubSurfaceBlocks);
	AddBlockLayerToArray(UnderGroundBlocks);
	AddBlockLayerToArray(MountainBlocks);
	for (int i = 0; i < BlockTypes.Num(); i++)
	{
		VertexData.Add(TArray<FVector>());
		VertexColors.Add(TArray<FColor>());
		VertexNormals.Add(TArray<FVector>());
		TriangleData.Add(TArray<int>());
		UVData.Add(TArray<FVector2D>());
		TangentData.Add(TArray<FProcMeshTangent>());
		VertexCount.Add(0);
		BlockTypes[i]->BlockID = i;
	}
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChunk::Generate()
{
	FTask GenBlocks = Launch(UE_SOURCE_LOCATION, [this]{GenerateBlocks();});

	FTask GenMesh = Launch(UE_SOURCE_LOCATION, [this]{GenerateMesh();}, GenBlocks);
	
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
			
			const int Height = GetHeightAtLocation(XPos, YPos, static_cast<float>(x) / Size, static_cast<float>(y) / Size);
			
			for (int z = 0; z <= Height; ++z)
			{
				Blocks[GetBlockIndex(x, y, z)] = GetBlockType(EBlockType::UnderGround);
			}
			
			if (Height > 4)
			{
				for (int z = Height - 3; z <= Height; ++z)
				{
					Blocks[GetBlockIndex(x, y, z)] = GetBlockType(EBlockType::SubSurface);
				}
			}
			
			// Everything above the height will be air
			for (int z = Height; z < Size; ++z)
			{
				Blocks[GetBlockIndex(x, y, z)] = GetBlockType(EBlockType::Air);
			}
			if (Height > Size * 0.5)
			{
				Blocks[GetBlockIndex(x, y, Height)] = GetBlockType(EBlockType::Mountain);
			}
			else
			{
				Blocks[GetBlockIndex(x, y, Height)] = GetBlockType(EBlockType::Surface);
			}
			
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
				if (Blocks[GetBlockIndex(x, y, z)].Type != EBlockType::Air && Blocks[GetBlockIndex(x, y, z)].Type != EBlockType::Null)
				{
					const auto Position = FVector(x, y, z);
					
					for (auto Direction : {EDirection::Forward, EDirection::Right, EDirection::Back, EDirection::Left, EDirection::Up, EDirection::Down})
					{
						if (Check(GetPositionInDirection(Direction, Position)))
						{
							CreateFace(Direction, Position * 100, Blocks[GetBlockIndex(x, y, z)]);
						}
					}
				}
			}
		}
	}
}

void AChunk::ApplyMesh()
{
	// TODO We aren't generating tangents at the moment
	for (int i = 0; i < BlockTypes.Num(); i++)
	{
		TArray<FVector> TempArray;
		//UKismetProceduralMeshLibrary::CalculateTangentsForMesh(VertexData[i], TriangleData[i], UVData[i], TempArray, TangentData[i]);
		Mesh->CreateMeshSection(i, VertexData[i], TriangleData[i], VertexNormals[i], UVData[i], 
								TArray<FColor>(), TangentData[i], GenerateCollision);
		Mesh->SetMaterial(i, BlockTypes[i]->Material);
	}
	
}

void AChunk::DisableMesh()
{
	for (int i = 0; i < BlockTypes.Num(); i++)
	{
		Mesh->ClearMeshSection(i);
	}
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
	
	return Blocks[GetBlockIndex(Position.X, Position.Y, Position.Z)].Type == EBlockType::Air || Blocks[GetBlockIndex(Position.X, Position.Y, Position.Z)].Type == EBlockType::Null;
}

void AChunk::CreateFace(EDirection Direction, FVector Position, FBlock BlockType)
{
	if (BlockType.Type == EBlockType::Air)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "Made air face");
	}
	int BlockIndex = BlockType.BlockID;
	VertexData[BlockIndex].Append(GetFaceVertices(Direction, Position));
	VertexColors[BlockIndex].Add({0, 255, 0});
	VertexColors[BlockIndex].Add({0, 255, 0});
	VertexColors[BlockIndex].Add({0, 255, 0});
	VertexColors[BlockIndex].Add({0, 255, 0});
	VertexNormals[BlockIndex].Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals[BlockIndex].Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals[BlockIndex].Add(DirectionVectors[static_cast<int>(Direction)]);
	VertexNormals[BlockIndex].Add(DirectionVectors[static_cast<int>(Direction)]);
	UVData[BlockIndex].Append({FVector2D(0, 0), FVector2D(1, 0), FVector2D(1, 1), FVector2D(0, 1)});
	TriangleData[BlockIndex].Append({VertexCount[BlockIndex] + 3, VertexCount[BlockIndex] + 2, VertexCount[BlockIndex], VertexCount[BlockIndex] + 2, VertexCount[BlockIndex] + 1, VertexCount[BlockIndex]});
	VertexCount[BlockIndex] += 4;
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

int AChunk::GetHeightAtLocation(float x, float y, float xProgress, float yProgress)
{
	int FinalOctaves = Octaves;
	float FinalHeightScalar = HeightScalar;
	float FinalRedistribPow = RedistributionPow;
	for (int i = 0; i < ChunkNeighbours.Num(); i++)
	{
		// If the direction is opposite then the progress percentage is inversed.
		FVector2D Dir = {xProgress, yProgress};
		if (ChunkNeighbours[i].Direction.X < 0)
		{
			Dir.X = (-xProgress * 100.f + 100) / 100.f;
		}
		if (ChunkNeighbours[i].Direction.Y < 0)
		{
			Dir.Y = (-yProgress * 100.f + 100) / 100.f;
		}
		if (Dir.X >= 0 && ChunkNeighbours[i].Direction.X != 0)
		{
			FinalOctaves = FMath::Lerp(FinalOctaves, (Octaves + ChunkNeighbours[i].Octaves) / 2, Dir.X / ChunkNeighbours.Num());
			//FinalOctaves /= 2.f;
			FinalHeightScalar = FMath::Lerp(FinalHeightScalar, (HeightScalar + ChunkNeighbours[i].HeightScalar) / 2, Dir.X / ChunkNeighbours.Num());
			//FinalHeightScalar /= 2.f;
			FinalRedistribPow = FMath::Lerp(FinalRedistribPow, (RedistributionPow + ChunkNeighbours[i].RedistribPow) / 2, Dir.X / ChunkNeighbours.Num());
			//FinalRedistribPow /= 2.f;
		}
		if (Dir.Y >= 0 && ChunkNeighbours[i].Direction.Y != 0)
		{
			FinalOctaves = FMath::Lerp(FinalOctaves, (Octaves + ChunkNeighbours[i].Octaves) / 2, Dir.Y / ChunkNeighbours.Num());
			//FinalOctaves /= 2.f;
			FinalHeightScalar = FMath::Lerp(FinalHeightScalar, (HeightScalar + ChunkNeighbours[i].HeightScalar) / 2, Dir.Y / ChunkNeighbours.Num());
			//FinalHeightScalar /= 2.f;
			FinalRedistribPow = FMath::Lerp(FinalRedistribPow, (RedistributionPow + ChunkNeighbours[i].RedistribPow) / 2, Dir.Y / ChunkNeighbours.Num());
			//FinalRedistribPow /= 2.f;
		}
	}
	
	float Total = 0.f;
	float ScalarTotal = 0.f;
	for (int i = 1; i <= FinalOctaves; ++i)
	{
		float Scalar = FMath::Pow(2.f, i - 1.f);
		ScalarTotal += 1.f / Scalar;
		Total += 1.f / Scalar * ((Noise->GetNoise(Scalar * x, Scalar * y) + 1.f) / 2.f);
	}
	return FMath::Clamp((FMath::Pow(Total / ScalarTotal * FinalHeightScalar, FinalRedistribPow)) * (Size / 2.f), 1, Size - 1);
}

FBlock AChunk::GetBlockType(EBlockType layer) const
{
	TArray<FBlock> BlockArray;
	switch (layer)
	{
	case EBlockType::Air:
		BlockArray = AirBlocks;
		break;
	case EBlockType::UnderGround:
		BlockArray = UnderGroundBlocks;
		break;
	case EBlockType::SubSurface:
		BlockArray = SubSurfaceBlocks;
		break;
	case EBlockType::Surface:
		BlockArray = SurfaceBlocks;
		break;
	case EBlockType::Null:
		BlockArray = AirBlocks;
		break;
	case EBlockType::Mountain:
		BlockArray = MountainBlocks;
		break;
	}
	// Count up the total probability score of all the blocks
	float TotalProb = 0.f;
	float HighestProb = 0.f;
	FBlock CommonBlock;
	for (int i = 0; i < BlockArray.Num(); ++i)
	{
		if (BlockArray[i].Probability > HighestProb)
		{
			HighestProb = BlockArray[i].Probability;
			CommonBlock = BlockArray[i];
		}
		TotalProb += BlockArray[i].Probability;
	}
	// Get a random number between 0 and the total probability score
	float Roll = FMath::RandRange(0.0f, TotalProb);
	for (int i = 0; i < BlockArray.Num(); ++i)
	{
		Roll -= BlockArray[i].Probability;
		if (Roll <= 0.f)
		{
			return BlockArray[i];
		}
	}
	
	return CommonBlock;
}

void AChunk::AddBlockLayerToArray(TArray<FBlock>& layer)
{
	for (int i = 0; i < layer.Num(); ++i)
	{
		BlockTypes.Add(&layer[i]);
	}
}

void AChunk::GenerateContainers()
{
	BlockTypes.Empty();
	VertexData.Empty();
	VertexColors.Empty();
	VertexNormals.Empty();
	TriangleData.Empty();
	UVData.Empty();
	TangentData.Empty();
	VertexCount.Empty();
	
	AddBlockLayerToArray(AirBlocks);
	AddBlockLayerToArray(SurfaceBlocks);
	AddBlockLayerToArray(SubSurfaceBlocks);
	AddBlockLayerToArray(UnderGroundBlocks);
	AddBlockLayerToArray(MountainBlocks);
	
	
	for (int i = 0; i < BlockTypes.Num(); ++i)
	{
		VertexData.Add(TArray<FVector>());
		VertexColors.Add(TArray<FColor>());
		VertexNormals.Add(TArray<FVector>());
		TriangleData.Add(TArray<int>());
		UVData.Add(TArray<FVector2D>());
		TangentData.Add(TArray<FProcMeshTangent>());
		VertexCount.Add(0);
		BlockTypes[i]->BlockID = i;
	}
}

void AChunk::ApplyBiomeEffects(AChunk* Biome)
{
	//AirBlocks.Append(Biome->AirBlocks);
	//SurfaceBlocks.Append(Biome->SurfaceBlocks);
	//SubSurfaceBlocks.Append(Biome->SubSurfaceBlocks);
	//UnderGroundBlocks.Append(Biome->UnderGroundBlocks);
	//MountainBlocks.Append(Biome->MountainBlocks);
	
	//GenerateContainers();
	
	RedistributionPow += Biome->RedistributionPow;
	RedistributionPow /= 2.f;
	
	HeightScalar += Biome->HeightScalar;
	HeightScalar /= 2.f;
	
	Octaves += Biome->Octaves;
	Octaves /= 2.f;
}

void AChunk::AddNeighbourBiome(FChunkNeighbour Biome)
{
	ChunkNeighbours.Emplace(Biome);
}

TArray<FVector2D> AChunk::GetNeighbours()
{
	return {
			{ChunkCoords.X + 1, ChunkCoords.Y},
			{ChunkCoords.X - 1, ChunkCoords.Y}, 
			{ChunkCoords.X, ChunkCoords.Y + 1}, 
			{ChunkCoords.X, ChunkCoords.Y - 1}
				};
}
