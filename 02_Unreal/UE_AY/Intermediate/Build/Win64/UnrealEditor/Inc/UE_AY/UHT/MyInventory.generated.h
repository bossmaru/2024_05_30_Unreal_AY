// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyInventory.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
#ifdef UE_AY_MyInventory_generated_h
#error "MyInventory.generated.h already included, missing '#pragma once' in MyInventory.h"
#endif
#define UE_AY_MyInventory_generated_h

#define FID_UE_AY_Source_UE_AY_MyInventory_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEraseItemImage); \
	DECLARE_FUNCTION(execSetItemImage);


#define FID_UE_AY_Source_UE_AY_MyInventory_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyInventory(); \
	friend struct Z_Construct_UClass_UMyInventory_Statics; \
public: \
	DECLARE_CLASS(UMyInventory, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE_AY"), NO_API) \
	DECLARE_SERIALIZER(UMyInventory)


#define FID_UE_AY_Source_UE_AY_MyInventory_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyInventory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyInventory(UMyInventory&&); \
	UMyInventory(const UMyInventory&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyInventory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyInventory); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyInventory) \
	NO_API virtual ~UMyInventory();


#define FID_UE_AY_Source_UE_AY_MyInventory_h_12_PROLOG
#define FID_UE_AY_Source_UE_AY_MyInventory_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_AY_Source_UE_AY_MyInventory_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyInventory_h_15_INCLASS_NO_PURE_DECLS \
	FID_UE_AY_Source_UE_AY_MyInventory_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE_AY_API UClass* StaticClass<class UMyInventory>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_AY_Source_UE_AY_MyInventory_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
