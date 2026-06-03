// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class VOXELTERRAINGENERATOR_API PoissonNoise
{
public:
	PoissonNoise();
	
	~PoissonNoise();
	
public:
	void GenerateNoise();

	FVector2D GetValue(int x, int y);
	
	void GenerateTexture();
private:
	
	FVector2D WorldToGrid(FVector2D Point);
	
	FVector2D GenerateRandomPointAround(FVector2D Point);
	
	bool InRect(FVector2D Point, FVector2D Rect);
	
	bool InNeighborhood(FVector2D Point);
	
	/**
	 * 
	 * @param Point Point to get all the cells around in a 2 cell distance
	 * @return All cells around the point in a 2 cell distance
	 */
	TArray<FVector2D> SquareAroundPoint(FVector2D Point);
private:
	// Map of grids/cells each cell can only have one point/vector2D
	TArray<TArray<FVector2D>> GridMap;
	
	// Array of all points
	TArray<FVector2D> Points;
	
	bool Generated = false;
	
	int MinDistance = 500;
	
	float CellSize;
	
	int NewPointCount = 30;
	
	int Width = 10000;
	int Height = 10000;
	
public:
	UTexture2D* Texture;
};
