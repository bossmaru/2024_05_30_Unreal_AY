// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AMyGameModeBase();

	virtual void BeginPlay() override;

	void SpawnMonsters();
	void SetInventoryWidget();

	UPROPERTY()
	UClass* _monsterClass;

	UPROPERTY()
	TArray<class AMyCharacter*> _monsters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> _inventoryWidgetClass;

	UPROPERTY()
	class UUserWidget* _inventoryWidget;
};
