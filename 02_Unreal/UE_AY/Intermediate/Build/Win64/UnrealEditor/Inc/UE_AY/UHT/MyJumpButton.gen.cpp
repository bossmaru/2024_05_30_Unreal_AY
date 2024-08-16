// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_AY/MyJumpButton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyJumpButton() {}

// Begin Cross Module References
UE_AY_API UClass* Z_Construct_UClass_UMyJumpButton();
UE_AY_API UClass* Z_Construct_UClass_UMyJumpButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_UE_AY();
// End Cross Module References

// Begin Class UMyJumpButton Function JumpButtonClicked
struct Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpButton, nullptr, "JumpButtonClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyJumpButton::execJumpButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JumpButtonClicked();
	P_NATIVE_END;
}
// End Class UMyJumpButton Function JumpButtonClicked

// Begin Class UMyJumpButton
void UMyJumpButton::StaticRegisterNativesUMyJumpButton()
{
	UClass* Class = UMyJumpButton::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "JumpButtonClicked", &UMyJumpButton::execJumpButtonClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyJumpButton);
UClass* Z_Construct_UClass_UMyJumpButton_NoRegister()
{
	return UMyJumpButton::StaticClass();
}
struct Z_Construct_UClass_UMyJumpButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyJumpButton.h" },
		{ "ModuleRelativePath", "MyJumpButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyJumpButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyJumpButton_JumpButtonClicked, "JumpButtonClicked" }, // 858223619
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyJumpButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyJumpButton_Statics::NewProp_JumpButton = { "JumpButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyJumpButton, JumpButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpButton_MetaData), NewProp_JumpButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyJumpButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyJumpButton_Statics::NewProp_JumpButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpButton_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyJumpButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_AY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyJumpButton_Statics::ClassParams = {
	&UMyJumpButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyJumpButton_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpButton_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyJumpButton_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyJumpButton()
{
	if (!Z_Registration_Info_UClass_UMyJumpButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyJumpButton.OuterSingleton, Z_Construct_UClass_UMyJumpButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyJumpButton.OuterSingleton;
}
template<> UE_AY_API UClass* StaticClass<UMyJumpButton>()
{
	return UMyJumpButton::StaticClass();
}
UMyJumpButton::UMyJumpButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyJumpButton);
UMyJumpButton::~UMyJumpButton() {}
// End Class UMyJumpButton

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyJumpButton_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyJumpButton, UMyJumpButton::StaticClass, TEXT("UMyJumpButton"), &Z_Registration_Info_UClass_UMyJumpButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyJumpButton), 24184749U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyJumpButton_h_2566925647(TEXT("/Script/UE_AY"),
	Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyJumpButton_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyJumpButton_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
