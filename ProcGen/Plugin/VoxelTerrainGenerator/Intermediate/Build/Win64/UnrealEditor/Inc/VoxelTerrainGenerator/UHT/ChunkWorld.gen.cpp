// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTerrainGenerator/Public/ChunkWorld.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChunkWorld() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_VoxelTerrainGenerator();
VOXELTERRAINGENERATOR_API UClass* Z_Construct_UClass_AChunk_NoRegister();
VOXELTERRAINGENERATOR_API UClass* Z_Construct_UClass_AChunkWorld();
VOXELTERRAINGENERATOR_API UClass* Z_Construct_UClass_AChunkWorld_NoRegister();
// End Cross Module References

// Begin Class AChunkWorld
void AChunkWorld::StaticRegisterNativesAChunkWorld()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AChunkWorld);
UClass* Z_Construct_UClass_AChunkWorld_NoRegister()
{
	return AChunkWorld::StaticClass();
}
struct Z_Construct_UClass_AChunkWorld_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ChunkWorld.h" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chunk_MetaData[] = {
		{ "Category", "Voxel World" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BiomeChunks_MetaData[] = {
		{ "Category", "Voxel World" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DrawDistance_MetaData[] = {
		{ "Category", "Voxel World" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChunkSize_MetaData[] = {
		{ "Category", "Voxel World" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TerrainSeed_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frequency_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BiomeFrequency_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChunksGeneratedPerFrame_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderDistance_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreLoadDistance_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[] = {
		{ "ModuleRelativePath", "Public/ChunkWorld.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_Chunk;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BiomeChunks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BiomeChunks;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DrawDistance;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChunkSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TerrainSeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BiomeFrequency;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChunksGeneratedPerFrame;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RenderDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreLoadDistance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChunkWorld>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_Chunk = { "Chunk", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, Chunk), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chunk_MetaData), NewProp_Chunk_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeChunks_Inner = { "BiomeChunks", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_AChunk_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeChunks = { "BiomeChunks", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, BiomeChunks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BiomeChunks_MetaData), NewProp_BiomeChunks_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_DrawDistance = { "DrawDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, DrawDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawDistance_MetaData), NewProp_DrawDistance_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_ChunkSize = { "ChunkSize", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, ChunkSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChunkSize_MetaData), NewProp_ChunkSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_TerrainSeed = { "TerrainSeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, TerrainSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TerrainSeed_MetaData), NewProp_TerrainSeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, Frequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frequency_MetaData), NewProp_Frequency_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeFrequency = { "BiomeFrequency", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, BiomeFrequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BiomeFrequency_MetaData), NewProp_BiomeFrequency_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_ChunksGeneratedPerFrame = { "ChunksGeneratedPerFrame", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, ChunksGeneratedPerFrame), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChunksGeneratedPerFrame_MetaData), NewProp_ChunksGeneratedPerFrame_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_RenderDistance = { "RenderDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, RenderDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderDistance_MetaData), NewProp_RenderDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_PreLoadDistance = { "PreLoadDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, PreLoadDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreLoadDistance_MetaData), NewProp_PreLoadDistance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChunkWorld_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunkWorld, Player), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player_MetaData), NewProp_Player_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChunkWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_Chunk,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeChunks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeChunks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_DrawDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_ChunkSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_TerrainSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_Frequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_BiomeFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_ChunksGeneratedPerFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_RenderDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_PreLoadDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunkWorld_Statics::NewProp_Player,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChunkWorld_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AChunkWorld_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VoxelTerrainGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChunkWorld_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AChunkWorld_Statics::ClassParams = {
	&AChunkWorld::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AChunkWorld_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AChunkWorld_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AChunkWorld_Statics::Class_MetaDataParams), Z_Construct_UClass_AChunkWorld_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AChunkWorld()
{
	if (!Z_Registration_Info_UClass_AChunkWorld.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AChunkWorld.OuterSingleton, Z_Construct_UClass_AChunkWorld_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AChunkWorld.OuterSingleton;
}
template<> VOXELTERRAINGENERATOR_API UClass* StaticClass<AChunkWorld>()
{
	return AChunkWorld::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AChunkWorld);
AChunkWorld::~AChunkWorld() {}
// End Class AChunkWorld

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkWorld_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AChunkWorld, AChunkWorld::StaticClass, TEXT("AChunkWorld"), &Z_Registration_Info_UClass_AChunkWorld, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AChunkWorld), 1648626771U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkWorld_h_2090926181(TEXT("/Script/VoxelTerrainGenerator"),
	Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkWorld_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_ChunkWorld_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
