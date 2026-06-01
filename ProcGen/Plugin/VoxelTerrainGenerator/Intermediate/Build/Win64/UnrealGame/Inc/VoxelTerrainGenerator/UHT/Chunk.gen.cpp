// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTerrainGenerator/Public/Chunk.h"
#include "VoxelTerrainGenerator/Public/Block.h"
#include "VoxelTerrainGenerator/Public/ChunkNeighbour.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChunk() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_VoxelTerrainGenerator();
VOXELTERRAINGENERATOR_API UClass* Z_Construct_UClass_AChunk();
VOXELTERRAINGENERATOR_API UClass* Z_Construct_UClass_AChunk_NoRegister();
VOXELTERRAINGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FBlock();
VOXELTERRAINGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FChunkNeighbour();
// End Cross Module References

// Begin Class AChunk
void AChunk::StaticRegisterNativesAChunk()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AChunk);
UClass* Z_Construct_UClass_AChunk_NoRegister()
{
	return AChunk::StaticClass();
}
struct Z_Construct_UClass_AChunk_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Chunk.h" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Size of the chunk is Size * Size * Size e.g if size is 32 each chunk will be 32 x 32 x 32 blocks.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Size of the chunk is Size * Size * Size e.g if size is 32 each chunk will be 32 x 32 x 32 blocks." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RedistributionPow_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Will raise the height values (0 - 1 values) to the power of this variable.\n\x09 * This will cause steeper cliffs and flatter valleys.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Will raise the height values (0 - 1 values) to the power of this variable.\nThis will cause steeper cliffs and flatter valleys." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Octaves_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Higher values will cause less randomness in the terrain and will smooth it out more.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Higher values will cause less randomness in the terrain and will smooth it out more." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeightScalar_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Multiply all height values by this scalar.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Multiply all height values by this scalar." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHeightRounding_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Whether height values will be rounded.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Whether height values will be rounded." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeightRoundingPower_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * To what value height values should be rounded.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "To what value height values should be rounded." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountainHeightRequirement_MetaData[] = {
		{ "Category", "Chunk" },
		{ "Comment", "/**\n\x09 * Above this requirement value the blocks will use blocks from the mountain blocks \n\x09 */" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
		{ "ToolTip", "Above this requirement value the blocks will use blocks from the mountain blocks" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderGroundBlocks_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubSurfaceBlocks_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceBlocks_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AirBlocks_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountainBlocks_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerateCollision_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnableShadows_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChunkCoords_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChunkNeighbours_MetaData[] = {
		{ "Category", "Chunk" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Chunk.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Size;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RedistributionPow;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Octaves;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HeightScalar;
	static void NewProp_bHeightRounding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHeightRounding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HeightRoundingPower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MountainHeightRequirement;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnderGroundBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UnderGroundBlocks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SubSurfaceBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SubSurfaceBlocks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfaceBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SurfaceBlocks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AirBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AirBlocks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MountainBlocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MountainBlocks;
	static void NewProp_GenerateCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_GenerateCollision;
	static void NewProp_EnableShadows_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableShadows;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChunkCoords;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChunkNeighbours_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ChunkNeighbours;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChunk>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, Size), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_RedistributionPow = { "RedistributionPow", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, RedistributionPow), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RedistributionPow_MetaData), NewProp_RedistributionPow_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_Octaves = { "Octaves", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, Octaves), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Octaves_MetaData), NewProp_Octaves_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_HeightScalar = { "HeightScalar", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, HeightScalar), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeightScalar_MetaData), NewProp_HeightScalar_MetaData) };
void Z_Construct_UClass_AChunk_Statics::NewProp_bHeightRounding_SetBit(void* Obj)
{
	((AChunk*)Obj)->bHeightRounding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_bHeightRounding = { "bHeightRounding", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChunk), &Z_Construct_UClass_AChunk_Statics::NewProp_bHeightRounding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHeightRounding_MetaData), NewProp_bHeightRounding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_HeightRoundingPower = { "HeightRoundingPower", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, HeightRoundingPower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeightRoundingPower_MetaData), NewProp_HeightRoundingPower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_MountainHeightRequirement = { "MountainHeightRequirement", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, MountainHeightRequirement), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountainHeightRequirement_MetaData), NewProp_MountainHeightRequirement_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_UnderGroundBlocks_Inner = { "UnderGroundBlocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBlock, METADATA_PARAMS(0, nullptr) }; // 2028639385
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_UnderGroundBlocks = { "UnderGroundBlocks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, UnderGroundBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderGroundBlocks_MetaData), NewProp_UnderGroundBlocks_MetaData) }; // 2028639385
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_SubSurfaceBlocks_Inner = { "SubSurfaceBlocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBlock, METADATA_PARAMS(0, nullptr) }; // 2028639385
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_SubSurfaceBlocks = { "SubSurfaceBlocks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, SubSurfaceBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubSurfaceBlocks_MetaData), NewProp_SubSurfaceBlocks_MetaData) }; // 2028639385
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_SurfaceBlocks_Inner = { "SurfaceBlocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBlock, METADATA_PARAMS(0, nullptr) }; // 2028639385
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_SurfaceBlocks = { "SurfaceBlocks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, SurfaceBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceBlocks_MetaData), NewProp_SurfaceBlocks_MetaData) }; // 2028639385
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_AirBlocks_Inner = { "AirBlocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBlock, METADATA_PARAMS(0, nullptr) }; // 2028639385
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_AirBlocks = { "AirBlocks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, AirBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AirBlocks_MetaData), NewProp_AirBlocks_MetaData) }; // 2028639385
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_MountainBlocks_Inner = { "MountainBlocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FBlock, METADATA_PARAMS(0, nullptr) }; // 2028639385
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_MountainBlocks = { "MountainBlocks", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, MountainBlocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountainBlocks_MetaData), NewProp_MountainBlocks_MetaData) }; // 2028639385
void Z_Construct_UClass_AChunk_Statics::NewProp_GenerateCollision_SetBit(void* Obj)
{
	((AChunk*)Obj)->GenerateCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_GenerateCollision = { "GenerateCollision", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChunk), &Z_Construct_UClass_AChunk_Statics::NewProp_GenerateCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerateCollision_MetaData), NewProp_GenerateCollision_MetaData) };
void Z_Construct_UClass_AChunk_Statics::NewProp_EnableShadows_SetBit(void* Obj)
{
	((AChunk*)Obj)->EnableShadows = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_EnableShadows = { "EnableShadows", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChunk), &Z_Construct_UClass_AChunk_Statics::NewProp_EnableShadows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnableShadows_MetaData), NewProp_EnableShadows_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_ChunkCoords = { "ChunkCoords", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, ChunkCoords), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChunkCoords_MetaData), NewProp_ChunkCoords_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_ChunkNeighbours_Inner = { "ChunkNeighbours", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChunkNeighbour, METADATA_PARAMS(0, nullptr) }; // 269594171
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_ChunkNeighbours = { "ChunkNeighbours", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, ChunkNeighbours), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChunkNeighbours_MetaData), NewProp_ChunkNeighbours_MetaData) }; // 269594171
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChunk_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChunk, Mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChunk_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_RedistributionPow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_Octaves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_HeightScalar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_bHeightRounding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_HeightRoundingPower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_MountainHeightRequirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_UnderGroundBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_UnderGroundBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_SubSurfaceBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_SubSurfaceBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_SurfaceBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_SurfaceBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_AirBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_AirBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_MountainBlocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_MountainBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_GenerateCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_EnableShadows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_ChunkCoords,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_ChunkNeighbours_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_ChunkNeighbours,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChunk_Statics::NewProp_Mesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChunk_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AChunk_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VoxelTerrainGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChunk_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AChunk_Statics::ClassParams = {
	&AChunk::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AChunk_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AChunk_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AChunk_Statics::Class_MetaDataParams), Z_Construct_UClass_AChunk_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AChunk()
{
	if (!Z_Registration_Info_UClass_AChunk.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AChunk.OuterSingleton, Z_Construct_UClass_AChunk_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AChunk.OuterSingleton;
}
template<> VOXELTERRAINGENERATOR_API UClass* StaticClass<AChunk>()
{
	return AChunk::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AChunk);
AChunk::~AChunk() {}
// End Class AChunk

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Chunk_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AChunk, AChunk::StaticClass, TEXT("AChunk"), &Z_Registration_Info_UClass_AChunk, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AChunk), 3591231359U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Chunk_h_494165296(TEXT("/Script/VoxelTerrainGenerator"),
	Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Chunk_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Chunk_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
