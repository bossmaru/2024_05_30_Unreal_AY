// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	void ShowUI();
	void HideUI();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* _inputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class APawn* _myPawn;
protected:
	virtual void BeginPlay() override;
};
