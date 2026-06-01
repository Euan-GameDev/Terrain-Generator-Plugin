// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VoxelTerrainGenerator/Public/Enums.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnums() {}

// Begin Cross Module References
UPackage* Z_Construct_UPackage__Script_VoxelTerrainGenerator();
VOXELTERRAINGENERATOR_API UEnum* Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType();
// End Cross Module References

// Begin Enum EBlockType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBlockType;
static UEnum* EBlockType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EBlockType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EBlockType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType, (UObject*)Z_Construct_UPackage__Script_VoxelTerrainGenerator(), TEXT("EBlockType"));
	}
	return Z_Registration_Info_UEnum_EBlockType.OuterSingleton;
}
template<> VOXELTERRAINGENERATOR_API UEnum* StaticEnum<EBlockType>()
{
	return EBlockType_StaticEnum();
}
struct Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Air.Name", "EBlockType::Air" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Enums.h" },
		{ "Mountain.Name", "EBlockType::Mountain" },
		{ "Null.Name", "EBlockType::Null" },
		{ "SubSurface.Name", "EBlockType::SubSurface" },
		{ "Surface.Name", "EBlockType::Surface" },
		{ "UnderGround.Name", "EBlockType::UnderGround" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBlockType::Air", (int64)EBlockType::Air },
		{ "EBlockType::UnderGround", (int64)EBlockType::UnderGround },
		{ "EBlockType::SubSurface", (int64)EBlockType::SubSurface },
		{ "EBlockType::Surface", (int64)EBlockType::Surface },
		{ "EBlockType::Mountain", (int64)EBlockType::Mountain },
		{ "EBlockType::Null", (int64)EBlockType::Null },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_VoxelTerrainGenerator,
	nullptr,
	"EBlockType",
	"EBlockType",
	Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType()
{
	if (!Z_Registration_Info_UEnum_EBlockType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBlockType.InnerSingleton, Z_Construct_UEnum_VoxelTerrainGenerator_EBlockType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EBlockType.InnerSingleton;
}
// End Enum EBlockType

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Enums_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EBlockType_StaticEnum, TEXT("EBlockType"), &Z_Registration_Info_UEnum_EBlockType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1465494078U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Enums_h_1216773062(TEXT("/Script/VoxelTerrainGenerator"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Enums_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Enums_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
