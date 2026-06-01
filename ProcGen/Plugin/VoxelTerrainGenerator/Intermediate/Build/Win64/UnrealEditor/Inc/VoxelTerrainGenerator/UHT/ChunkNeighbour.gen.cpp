// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTerrainGenerator/Public/ChunkNeighbour.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChunkNeighbour() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_VoxelTerrainGenerator();
VOXELTERRAINGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FChunkNeighbour();
// End Cross Module References

// Begin ScriptStruct FChunkNeighbour
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ChunkNeighbour;
class UScriptStruct* FChunkNeighbour::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ChunkNeighbour.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ChunkNeighbour.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FChunkNeighbour, (UObject*)Z_Construct_UPackage__Script_VoxelTerrainGenerator(), TEXT("ChunkNeighbour"));
	}
	return Z_Registration_Info_UScriptStruct_ChunkNeighbour.OuterSingleton;
}
template<> VOXELTERRAINGENERATOR_API UScriptStruct* StaticStruct<FChunkNeighbour>()
{
	return FChunkNeighbour::StaticStruct();
}
struct Z_Construct_UScriptStruct_FChunkNeighbour_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ChunkNeighbour.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChunkNeighbour>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChunkNeighbour_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_VoxelTerrainGenerator,
	nullptr,
	&NewStructOps,
	"ChunkNeighbour",
	nullptr,
	0,
	sizeof(FChunkNeighbour),
	alignof(FChunkNeighbour),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChunkNeighbour_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FChunkNeighbour_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FChunkNeighbour()
{
	if (!Z_Registration_Info_UScriptStruct_ChunkNeighbour.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ChunkNeighbour.InnerSingleton, Z_Construct_UScriptStruct_FChunkNeighbour_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ChunkNeighbour.InnerSingleton;
}
// End ScriptStruct FChunkNeighbour

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkNeighbour_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FChunkNeighbour::StaticStruct, Z_Construct_UScriptStruct_FChunkNeighbour_Statics::NewStructOps, TEXT("ChunkNeighbour"), &Z_Registration_Info_UScriptStruct_ChunkNeighbour, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FChunkNeighbour), 269594171U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkNeighbour_h_2110354702(TEXT("/Script/VoxelTerrainGenerator"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkNeighbour_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkNeighbour_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
