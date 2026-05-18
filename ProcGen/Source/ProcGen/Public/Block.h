#pragma once
#include "Enums.h"
#include "Block.generated.h"

USTRUCT(BlueprintType)
struct FBlock
{
	GENERATED_BODY()
public:
	FBlock()
	{
		Type = EBlockType::Air;
		Probability = 0.f;
	};
	UPROPERTY(BlueprintReadWrite)
	EBlockType Type;
	UPROPERTY(BlueprintReadWrite)
	float Probability;
};
