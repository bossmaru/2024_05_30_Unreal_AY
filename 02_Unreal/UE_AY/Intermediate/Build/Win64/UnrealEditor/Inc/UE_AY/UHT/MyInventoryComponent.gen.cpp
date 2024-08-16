// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_AY/MyInventoryComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInventoryComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UE_AY_API UClass* Z_Construct_UClass_AMyItem_NoRegister();
UE_AY_API UClass* Z_Construct_UClass_UMyInventoryComponent();
UE_AY_API UClass* Z_Construct_UClass_UMyInventoryComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_UE_AY();
// End Cross Module References

// Begin Class UMyInventoryComponent Function DropItem
struct Z_Construct_UFunction_UMyInventoryComponent_DropItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyInventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyInventoryComponent_DropItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyInventoryComponent, nullptr, "DropItem", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInventoryComponent_DropItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyInventoryComponent_DropItem_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMyInventoryComponent_DropItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyInventoryComponent_DropItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyInventoryComponent::execDropItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DropItem();
	P_NATIVE_END;
}
// End Class UMyInventoryComponent Function DropItem

// Begin Class UMyInventoryComponent
void UMyInventoryComponent::StaticRegisterNativesUMyInventoryComponent()
{
	UClass* Class = UMyInventoryComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DropItem", &UMyInventoryComponent::execDropItem },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyInventoryComponent);
UClass* Z_Construct_UClass_UMyInventoryComponent_NoRegister()
{
	return UMyInventoryComponent::StaticClass();
}
struct Z_Construct_UClass_UMyInventoryComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyInventoryComponent.h" },
		{ "ModuleRelativePath", "MyInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__items_MetaData[] = {
		{ "ModuleRelativePath", "MyInventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp__items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyInventoryComponent_DropItem, "DropItem" }, // 3789924863
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInventoryComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventoryComponent_Statics::NewProp__items_Inner = { "_items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMyItem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyInventoryComponent_Statics::NewProp__items = { "_items", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInventoryComponent, _items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__items_MetaData), NewProp__items_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventoryComponent_Statics::NewProp__items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventoryComponent_Statics::NewProp__items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyInventoryComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_AY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyInventoryComponent_Statics::ClassParams = {
	&UMyInventoryComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyInventoryComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventoryComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyInventoryComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyInventoryComponent()
{
	if (!Z_Registration_Info_UClass_UMyInventoryComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyInventoryComponent.OuterSingleton, Z_Construct_UClass_UMyInventoryComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyInventoryComponent.OuterSingleton;
}
template<> UE_AY_API UClass* StaticClass<UMyInventoryComponent>()
{
	return UMyInventoryComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInventoryComponent);
UMyInventoryComponent::~UMyInventoryComponent() {}
// End Class UMyInventoryComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventoryComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyInventoryComponent, UMyInventoryComponent::StaticClass, TEXT("UMyInventoryComponent"), &Z_Registration_Info_UClass_UMyInventoryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyInventoryComponent), 682296581U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventoryComponent_h_394731975(TEXT("/Script/UE_AY"),
	Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventoryComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventoryComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
