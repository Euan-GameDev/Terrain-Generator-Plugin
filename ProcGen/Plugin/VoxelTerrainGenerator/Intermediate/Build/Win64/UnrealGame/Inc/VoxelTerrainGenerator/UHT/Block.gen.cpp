// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTerrainGenerator/Public/Block.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlock() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
UPackage* Z_Construct_UPackage__Script_VoxelTerrainGenerator();
VOXELTERRAINGENERATOR_API UEnum* Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType();
VOXELTERRAINGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FBlock();
// End Cross Module References

// Begin ScriptStruct FBlock
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Block;
class UScriptStruct* FBlock::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Block.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Block.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBlock, (UObject*)Z_Construct_UPackage__Script_VoxelTerrainGenerator(), TEXT("Block"));
	}
	return Z_Registration_Info_UScriptStruct_Block.OuterSingleton;
}
template<> VOXELTERRAINGENERATOR_API UScriptStruct* StaticStruct<FBlock>()
{
	return FBlock::StaticStruct();
}
struct Z_Construct_UScriptStruct_FBlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Block.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Block" },
		{ "ModuleRelativePath", "Public/Block.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Probability_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Block" },
		{ "ModuleRelativePath", "Public/Block.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Block" },
		{ "ModuleRelativePath", "Public/Block.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockID_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Block" },
		{ "ModuleRelativePath", "Public/Block.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Probability;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BlockID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBlock>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBlock, Type), Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 1465494078
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Probability = { "Probability", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBlock, Probability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Probability_MetaData), NewProp_Probability_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBlock, Material), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Material_MetaData), NewProp_Material_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBlock_Statics::NewProp_BlockID = { "BlockID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBlock, BlockID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockID_MetaData), NewProp_BlockID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBlock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Probability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBlock_Statics::NewProp_Material,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBlock_Statics::NewProp_BlockID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBlock_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBlock_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_VoxelTerrainGenerator,
	nullptr,
	&NewStructOps,
	"Block",
	Z_Construct_UScriptStruct_FBlock_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBlock_Statics::PropPointers),
	sizeof(FBlock),
	alignof(FBlock),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBlock_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBlock_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FBlock()
{
	if (!Z_Registration_Info_UScriptStruct_Block.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Block.InnerSingleton, Z_Construct_UScriptStruct_FBlock_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Block.InnerSingleton;
}
// End ScriptStruct FBlock

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Block_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FBlock::StaticStruct, Z_Construct_UScriptStruct_FBlock_Statics::NewStructOps, TEXT("Block"), &Z_Registration_Info_UScriptStruct_Block, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBlock), 2028639385U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Block_h_3260141474(TEXT("/Script/VoxelTerrainGenerator"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Block_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Block_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
