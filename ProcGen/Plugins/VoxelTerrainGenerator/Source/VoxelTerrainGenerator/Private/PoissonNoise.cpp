// Fill out your copyright notice in the Description page of Project Settings.


#include "PoissonNoise.h"


PoissonNoise::PoissonNoise()
	: CellSize{ 0.f }
{
	Texture = UTexture2D::CreateTransient(Width, Height);
	Texture->UpdateResource();
}

PoissonNoise::~PoissonNoise()
{
}

void PoissonNoise::GenerateNoise()
{
	// Set up the noise map
	CellSize = MinDistance / sqrt(2);
	
	GridMap.SetNum(Width/CellSize);
	for (TArray Column : GridMap)
	{
		Column.SetNum(Height/CellSize);
	}
	
	// Set up a queue, items should be taken from this queue randomly instead of in order
	TArray<FVector2D> ProcessList;
	TArray<FVector2D> SamplePoints;
	
	// Generate the first point randomly and add it to our containers
	FVector2D FirstPoint = {static_cast<float>(FMath::RandRange(0, Width)), static_cast<float>(FMath::RandRange(0, Height))};
	ProcessList.Add(FirstPoint);
	SamplePoints.Add(FirstPoint);
	GridMap[WorldToGrid(FirstPoint).X][WorldToGrid(FirstPoint).Y] = FirstPoint;
	
	// Generate other points from point in queue
	while (!ProcessList.IsEmpty())
	{
		FVector2D Point = ProcessList[FMath::RandRange(0, ProcessList.Num() - 1)];
		ProcessList.Remove(Point);
		for (int i = 0; i < NewPointCount; i++)
		{
			FVector2D NewPoint = GenerateRandomPointAround(Point);
			// TODO FOLLOWING POISSON DISK SAMPLING PSUEDOCODE THIS IS WORDED WEIRDLY ATM
			// Check that the point is in the grid
			// and no points exist in the points neighbourhood
			if (InRect(NewPoint, {static_cast<double>(Width), static_cast<double>(Height)}) && !InNeighborhood(NewPoint))
			{
				// Update containers
				ProcessList.Add(NewPoint);
				SamplePoints.Add(NewPoint);
				GridMap[WorldToGrid(NewPoint).X][WorldToGrid(NewPoint).Y] = NewPoint;
			}
		}
	}
	Generated = true;
}

FVector2D PoissonNoise::GetValue(int x, int y)
{
	return GridMap[x / CellSize][y / CellSize];
}

void PoissonNoise::GenerateTexture()
{
	FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];
	void* TextureData = Mip.BulkData.Lock(LOCK_READ_WRITE);
	
	uint8* RawPixels = static_cast<uint8*>(TextureData);
	// Set the entire canvas to be white
	for (int32 y = 0; y < Height; y++)
	{
		for (int32 x = 0; x < Width; x++)
		{
			int32 Index = ((x * Width) + x) * 4;
			
			RawPixels[Index] = 255; // red
			RawPixels[Index + 1] = 255; // green
			RawPixels[Index + 2] = 255; // blue
			RawPixels[Index + 3] = 255; // alpha
		}
	}
	
	for (int i = 0; i < Points.Num(); i++)
	{
		int32 Index = (Points[i].X * Width + Points[i].Y) * 4;
		
		RawPixels[Index] = 0; // red
		RawPixels[Index + 1] = 0; // green
		RawPixels[Index + 2] = 0; // blue
		RawPixels[Index + 3] = 0; // alpha
	}
	
	Mip.BulkData.Unlock();
	
	Texture->UpdateResource();
}

FVector2D PoissonNoise::WorldToGrid(FVector2D Point)
{
	return {Point.X / CellSize, Point.Y / CellSize};
}

FVector2D PoissonNoise::GenerateRandomPointAround(FVector2D Point)
{
	// Non-uniform, favours points closer to the inner ring, leads to denser packings
	double R1 = FMath::RandRange(0.f, 1.f);
	double R2 = FMath::RandRange(0.f, 1.f);
	
	// Random radius between MinDist and 2 * MinDist
	float Radius = MinDistance * (R1 + 1);
	// Random angle
	float Angle = 2 * PI * R2;
	
	// The new point is generated around the inputted point
	return {Point.X + Radius * cos(Angle), Point.Y + Radius * sin(Angle)};
}

bool PoissonNoise::InRect(FVector2D Point, FVector2D Rect)
{
	if (Point.X < Rect.X && Point.X > 0 && Point.Y < Rect.Y && Point.Y > 0)
	{
		return true;
	}
	return false;
}

bool PoissonNoise::InNeighborhood(FVector2D Point)
{
	FVector2D GridPoint = WorldToGrid(Point);
	// Get the neighbourhood if the point in the grid
	TArray<FVector2D> CellsAroundPoint = SquareAroundPoint(GridPoint);
	for (FVector2D cell : CellsAroundPoint)
	{
		if (FVector2D::Distance(GridMap[cell.X][cell.Y], Point) < MinDistance)
		{
			return true;
		}
	}
	return false;
}

TArray<FVector2D> PoissonNoise::SquareAroundPoint(FVector2D Point)
{
	TArray<FVector2D> CellsAroundPoint;
	// Make sure that the cells are in the range of our gridmap
	int XStart = FMath::Max(Point.X - 2, 0);
	int YStart = FMath::Max(Point.Y - 2, 0);
	int XEnd = FMath::Min(Point.X + 2, GridMap.Num() - 1 );
	int YEnd = FMath::Min(Point.Y + 2, GridMap[XEnd].Num() - 1 );
	
	for (int x = XStart; x < XEnd; x++)
	{
		for (int y = YStart; y < YEnd; y++)
		{
			CellsAroundPoint.Add({static_cast<double>(x), static_cast<double>(y)});
		}
	}
	return CellsAroundPoint;
}
