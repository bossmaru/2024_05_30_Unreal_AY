// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE_AY/MyInventory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInventory() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UE_AY_API UClass* Z_Construct_UClass_UMyInventory();
UE_AY_API UClass* Z_Construct_UClass_UMyInventory_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_UE_AY();
// End Cross Module References

// Begin Class UMyInventory Function EraseItemImage
struct Z_Construct_UFunction_UMyInventory_EraseItemImage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// void SetItemImage(int32 index, int32 itemID);\n" },
#endif
		{ "ModuleRelativePath", "MyInventory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "void SetItemImage(int32 index, int32 itemID);" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyInventory_EraseItemImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyInventory, nullptr, "EraseItemImage", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInventory_EraseItemImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyInventory_EraseItemImage_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMyInventory_EraseItemImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyInventory_EraseItemImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyInventory::execEraseItemImage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EraseItemImage();
	P_NATIVE_END;
}
// End Class UMyInventory Function EraseItemImage

// Begin Class UMyInventory Function SetItemImage
struct Z_Construct_UFunction_UMyInventory_SetItemImage_Statics
{
	struct MyInventory_eventSetItemImage_Parms
	{
		int32 index;
		UTexture2D* itemImage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_index;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_itemImage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyInventory_eventSetItemImage_Parms, index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::NewProp_itemImage = { "itemImage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyInventory_eventSetItemImage_Parms, itemImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::NewProp_index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::NewProp_itemImage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyInventory, nullptr, "SetItemImage", nullptr, nullptr, Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::MyInventory_eventSetItemImage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::MyInventory_eventSetItemImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyInventory_SetItemImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyInventory_SetItemImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyInventory::execSetItemImage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_index);
	P_GET_OBJECT(UTexture2D,Z_Param_itemImage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemImage(Z_Param_index,Z_Param_itemImage);
	P_NATIVE_END;
}
// End Class UMyInventory Function SetItemImage

// Begin Class UMyInventory
void UMyInventory::StaticRegisterNativesUMyInventory()
{
	UClass* Class = UMyInventory::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EraseItemImage", &UMyInventory::execEraseItemImage },
		{ "SetItemImage", &UMyInventory::execSetItemImage },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyInventory);
UClass* Z_Construct_UClass_UMyInventory_NoRegister()
{
	return UMyInventory::StaticClass();
}
struct Z_Construct_UClass_UMyInventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyInventory.h" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__isVisible_MetaData[] = {
		{ "ModuleRelativePath", "MyInventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotGrid_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DropButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__itemButtons_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__itemButtonImages_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInventory.h" },
	};
#endif // WITH_METADATA
	static void NewProp__isVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__isVisible;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DropButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__itemButtons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp__itemButtons;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__itemButtonImages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp__itemButtonImages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyInventory_EraseItemImage, "EraseItemImage" }, // 1034467018
		{ &Z_Construct_UFunction_UMyInventory_SetItemImage, "SetItemImage" }, // 913667124
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInventory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UMyInventory_Statics::NewProp__isVisible_SetBit(void* Obj)
{
	((UMyInventory*)Obj)->_isVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp__isVisible = { "_isVisible", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMyInventory), &Z_Construct_UClass_UMyInventory_Statics::NewProp__isVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__isVisible_MetaData), NewProp__isVisible_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp_SlotGrid = { "SlotGrid", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInventory, SlotGrid), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotGrid_MetaData), NewProp_SlotGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp_DropButton = { "DropButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInventory, DropButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DropButton_MetaData), NewProp_DropButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtons_Inner = { "_itemButtons", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtons = { "_itemButtons", nullptr, (EPropertyFlags)0x001000800000000d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInventory, _itemButtons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__itemButtons_MetaData), NewProp__itemButtons_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtonImages_Inner = { "_itemButtonImages", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtonImages = { "_itemButtonImages", nullptr, (EPropertyFlags)0x001000800000000d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInventory, _itemButtonImages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__itemButtonImages_MetaData), NewProp__itemButtonImages_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyInventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp__isVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp_SlotGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp_DropButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtonImages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInventory_Statics::NewProp__itemButtonImages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventory_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyInventory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_UE_AY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyInventory_Statics::ClassParams = {
	&UMyInventory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyInventory_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventory_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInventory_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyInventory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyInventory()
{
	if (!Z_Registration_Info_UClass_UMyInventory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyInventory.OuterSingleton, Z_Construct_UClass_UMyInventory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyInventory.OuterSingleton;
}
template<> UE_AY_API UClass* StaticClass<UMyInventory>()
{
	return UMyInventory::StaticClass();
}
UMyInventory::UMyInventory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInventory);
UMyInventory::~UMyInventory() {}
// End Class UMyInventory

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyInventory, UMyInventory::StaticClass, TEXT("UMyInventory"), &Z_Registration_Info_UClass_UMyInventory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyInventory), 1224545928U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventory_h_751966774(TEXT("/Script/UE_AY"),
	Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_AY_Source_UE_AY_MyInventory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
