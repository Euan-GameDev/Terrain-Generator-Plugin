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
		Type = EBlockType::Null;
		Probability = 0.f;
		Material = nullptr;
		BlockID = -1;
	};
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	EBlockType Type;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	float Probability;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	UMaterial* Material;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	int BlockID;
	
};
