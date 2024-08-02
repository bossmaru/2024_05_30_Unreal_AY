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
	void ToggleVisiblity();

	UPROPERTY()
	bool _isVisible = false;
};
