// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUE_AY_init() {}
	UE_AY_API UFunction* Z_Construct_UDelegateFunction_UE_AY_AttackHitEventDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UE_AY;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UE_AY()
	{
		if (!Z_Registration_Info_UPackage__Script_UE_AY.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UE_AY_AttackHitEventDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UE_AY",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x6B0D2E95,
				0xFEDA06F5,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UE_AY.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UE_AY.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UE_AY(Z_Construct_UPackage__Script_UE_AY, TEXT("/Script/UE_AY"), Z_Registration_Info_UPackage__Script_UE_AY, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x6B0D2E95, 0xFEDA06F5));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
