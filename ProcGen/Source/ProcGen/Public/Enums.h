#pragma once

enum class EDirection
{
	Forward,
	Right,
	Back,
	Left,
	Up,
	Down
};

/*UENUM (BlueprintType)
enum class EBlockType : uint8
{
	Air,
	Stone,
	Dirt,
	Grass,
	Iron,
	Null
};*/

UENUM (BlueprintType)
enum class EBlockType : uint8
{
	Air,
	UnderGround,
	SubSurface,
	Surface,
	Null
};