#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Materials/Material.h"
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
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"), Category = "Block")
	EBlockType Type;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"), Category = "Block")
	float Probability;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"), Category = "Block")
	UMaterial* Material;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"), Category = "Block")
	int BlockID;
	
};
