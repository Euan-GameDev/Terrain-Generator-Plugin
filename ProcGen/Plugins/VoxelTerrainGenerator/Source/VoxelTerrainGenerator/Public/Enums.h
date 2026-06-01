#pragma once

#include "CoreMinimal.h"
#include "Enums.generated.h"

enum class EDirection
{
	Forward,
	Right,
	Back,
	Left,
	Up,
	Down
};

UENUM (BlueprintType)
enum class EBlockType : uint8
{
	Air,
	UnderGround,
	SubSurface,
	Surface,
	Mountain,
	Null
};