// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_AY/MyMonster.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyMonster() {}

// Begin Cross Module References
UE_AY_API UClass* Z_Construct_UClass_AMyCharacter();
UE_AY_API UClass* Z_Construct_UClass_AMyMonster();
UE_AY_API UClass* Z_Construct_UClass_AMyMonster_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE_AY();
// End Cross Module References

// Begin Class AMyMonster Function Attack_AI
struct Z_Construct_UFunction_AMyMonster_Attack_AI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMonster.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyMonster_Attack_AI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyMonster, nullptr, "Attack_AI", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyMonster_Attack_AI_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyMonster_Attack_AI_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyMonster_Attack_AI()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyMonster_Attack_AI_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyMonster::execAttack_AI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Attack_AI();
	P_NATIVE_END;
}
// End Class AMyMonster Function Attack_AI

// Begin Class AMyMonster
void AMyMonster::StaticRegisterNativesAMyMonster()
{
	UClass* Class = AMyMonster::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Attack_AI", &AMyMonster::execAttack_AI },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyMonster);
UClass* Z_Construct_UClass_AMyMonster_NoRegister()
{
	return AMyMonster::StaticClass();
}
struct Z_Construct_UClass_AMyMonster_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyMonster.h" },
		{ "ModuleRelativePath", "MyMonster.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyMonster_Attack_AI, "Attack_AI" }, // 4017632496
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyMonster>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMyMonster_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AMyCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_AY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyMonster_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyMonster_Statics::ClassParams = {
	&AMyMonster::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyMonster_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyMonster_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyMonster()
{
	if (!Z_Registration_Info_UClass_AMyMonster.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyMonster.OuterSingleton, Z_Construct_UClass_AMyMonster_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyMonster.OuterSingleton;
}
template<> UE_AY_API UClass* StaticClass<AMyMonster>()
{
	return AMyMonster::StaticClass();
}
AMyMonster::AMyMonster() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyMonster);
AMyMonster::~AMyMonster() {}
// End Class AMyMonster

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyMonster_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyMonster, AMyMonster::StaticClass, TEXT("AMyMonster"), &Z_Registration_Info_UClass_AMyMonster, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyMonster), 3027936133U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyMonster_h_851887192(TEXT("/Script/UE_AY"),
	Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyMonster_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyMonster_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
