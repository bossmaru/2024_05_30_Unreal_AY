// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_AY/MyHpBar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyHpBar() {}

// Begin Cross Module References
UE_AY_API UClass* Z_Construct_UClass_UMyHpBar();
UE_AY_API UClass* Z_Construct_UClass_UMyHpBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_UE_AY();
// End Cross Module References

// Begin Class UMyHpBar
void UMyHpBar::StaticRegisterNativesUMyHpBar()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyHpBar);
UClass* Z_Construct_UClass_UMyHpBar_NoRegister()
{
	return UMyHpBar::StaticClass();
}
struct Z_Construct_UClass_UMyHpBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyHpBar.h" },
		{ "ModuleRelativePath", "MyHpBar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PB_HpBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyHpBar.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PB_HpBar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyHpBar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyHpBar_Statics::NewProp_PB_HpBar = { "PB_HpBar", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyHpBar, PB_HpBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PB_HpBar_MetaData), NewProp_PB_HpBar_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyHpBar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyHpBar_Statics::NewProp_PB_HpBar,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyHpBar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_AY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyHpBar_Statics::ClassParams = {
	&UMyHpBar::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMyHpBar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyHpBar_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyHpBar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyHpBar()
{
	if (!Z_Registration_Info_UClass_UMyHpBar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyHpBar.OuterSingleton, Z_Construct_UClass_UMyHpBar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyHpBar.OuterSingleton;
}
template<> UE_AY_API UClass* StaticClass<UMyHpBar>()
{
	return UMyHpBar::StaticClass();
}
UMyHpBar::UMyHpBar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyHpBar);
UMyHpBar::~UMyHpBar() {}
// End Class UMyHpBar

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyHpBar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyHpBar, UMyHpBar::StaticClass, TEXT("UMyHpBar"), &Z_Registration_Info_UClass_UMyHpBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyHpBar), 881630016U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyHpBar_h_1614957491(TEXT("/Script/UE_AY"),
	Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyHpBar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyHpBar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
