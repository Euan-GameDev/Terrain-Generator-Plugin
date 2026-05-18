#pragma once
#include "Enums.h"

struct Block
{
public:
	Block()
	{
		Type = EBlockType::Air;
		Probability = 0.f;
	};
	EBlockType Type;
	float Probability;
};
