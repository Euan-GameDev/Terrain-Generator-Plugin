#pragma once

#include "ChunkNeighbour.generated.h"

USTRUCT()
struct FChunkNeighbour
{
	GENERATED_BODY()
public:
	FChunkNeighbour()
	{
		Direction = {0, 0};
		RedistribPow = 1.f;
		HeightScalar = 1.f;
		Octaves = 1;
	};
	FChunkNeighbour(FVector2D Dir, float Redistrib, float Height, int Oct)
	{
		Direction = Dir;
		RedistribPow = Redistrib;
		HeightScalar = Height;
		Octaves = Oct;
	};
	FVector2D Direction;
	float RedistribPow;
	float HeightScalar;
	int Octaves;
	
};
