// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enums.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VOXELTERRAINGENERATOR_Enums_generated_h
#error "Enums.generated.h already included, missing '#pragma once' in Enums.h"
#endif
#define VOXELTERRAINGENERATOR_Enums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_s240852_Documents_GitHub_ComplexGameSystems_ProcGen_Plugin_VoxelTerrainGenerator_HostProject_Plugins_VoxelTerrainGenerator_Source_VoxelTerrainGenerator_Public_Enums_h


#define FOREACH_ENUM_EBLOCKTYPE(op) \
	op(EBlockType::Air) \
	op(EBlockType::UnderGround) \
	op(EBlockType::SubSurface) \
	op(EBlockType::Surface) \
	op(EBlockType::Mountain) \
	op(EBlockType::Null) 

enum class EBlockType : uint8;
template<> struct TIsUEnumClass<EBlockType> { enum { Value = true }; };
template<> VOXELTERRAINGENERATOR_API UEnum* StaticEnum<EBlockType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
