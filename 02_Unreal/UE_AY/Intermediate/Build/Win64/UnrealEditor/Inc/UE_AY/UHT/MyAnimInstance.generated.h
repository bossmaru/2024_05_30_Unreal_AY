// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UE_AY_MyAnimInstance_generated_h
#error "MyAnimInstance.generated.h already included, missing '#pragma once' in MyAnimInstance.h"
#endif
#define UE_AY_MyAnimInstance_generated_h

#define FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnimNotify_Death); \
	DECLARE_FUNCTION(execAnimNotify_AttackHit);


#define FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyAnimInstance(); \
	friend struct Z_Construct_UClass_UMyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UE_AY"), NO_API) \
	DECLARE_SERIALIZER(UMyAnimInstance)


#define FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyAnimInstance(UMyAnimInstance&&); \
	UMyAnimInstance(const UMyAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyAnimInstance) \
	NO_API virtual ~UMyAnimInstance();


#define FID_UE_AY_Source_UE_AY_MyAnimInstance_h_14_PROLOG
#define FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_INCLASS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyAnimInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE_AY_API UClass* StaticClass<class UMyAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_AY_Source_UE_AY_MyAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
