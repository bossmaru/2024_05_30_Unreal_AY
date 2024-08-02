// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyJumpButton.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API UMyJumpButton : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* JumpButton;

	UFUNCTION()
	void JumpButtonClicked();
};
