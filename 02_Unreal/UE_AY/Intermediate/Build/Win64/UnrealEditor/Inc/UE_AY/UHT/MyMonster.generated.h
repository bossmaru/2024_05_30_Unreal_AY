// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyMonster.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UE_AY_MyMonster_generated_h
#error "MyMonster.generated.h already included, missing '#pragma once' in MyMonster.h"
#endif
#define UE_AY_MyMonster_generated_h

#define FID_UE_AY_Source_UE_AY_MyMonster_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAttack_AI);


#define FID_UE_AY_Source_UE_AY_MyMonster_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyMonster(); \
	friend struct Z_Construct_UClass_AMyMonster_Statics; \
public: \
	DECLARE_CLASS(AMyMonster, AMyCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UE_AY"), NO_API) \
	DECLARE_SERIALIZER(AMyMonster)


#define FID_UE_AY_Source_UE_AY_MyMonster_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyMonster(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyMonster(AMyMonster&&); \
	AMyMonster(const AMyMonster&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyMonster); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyMonster); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyMonster) \
	NO_API virtual ~AMyMonster();


#define FID_UE_AY_Source_UE_AY_MyMonster_h_12_PROLOG
#define FID_UE_AY_Source_UE_AY_MyMonster_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_AY_Source_UE_AY_MyMonster_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyMonster_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyMonster_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE_AY_API UClass* StaticClass<class AMyMonster>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_AY_Source_UE_AY_MyMonster_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
