// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyInventory.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API UMyInventory : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void SetButtons();

	void ToggleVisiblity();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemImage(int32 index, UTexture2D* itemImage);
	// void SetItemImage(int32 index, int32 itemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void EraseItemImage();

	UPROPERTY()
	bool _isVisible = false;

	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotGrid;

	UPROPERTY(meta = (BindWidget))
	class UButton* DropButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<class UButton*> _itemButtons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<class UImage*> _itemButtonImages;

	class UTexture2D* _default;
};
