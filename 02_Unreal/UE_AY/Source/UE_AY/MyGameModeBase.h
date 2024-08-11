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

	UFUNCTION()
	void ViewInventory();

	UFUNCTION()
	void AddItemToInventory();

	UFUNCTION()
	void DropItemFromInventory();

	UPROPERTY()
	UClass* _monsterClass;

	UPROPERTY()
	TArray<class AMyCharacter*> _monsters;

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	// TSubclassOf<UUserWidget> _inventoryWidgetClass;
	//UCLASS 매크로가 있고, UObject를 상속받는 클래스 자체를 저장할 수 있는 변수 자료형

	// UPROPERTY()
	// class UMyInventoryComponent* _inventoryComponent;
};
