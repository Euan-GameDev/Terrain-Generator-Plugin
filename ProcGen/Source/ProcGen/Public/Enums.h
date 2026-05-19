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

UENUM (BlueprintType)
enum class EBlockType : uint8
{
	Air,
	Stone,
	Dirt,
	Grass,
	Null
};