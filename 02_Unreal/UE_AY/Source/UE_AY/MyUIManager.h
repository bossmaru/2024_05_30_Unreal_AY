// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyUIManager.generated.h"

UCLASS()
class UE_AY_API AMyUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class UMyInventory* GetInvenUI() { return _inventoryWidget; };

private:
	UPROPERTY()
	class UMyInventory* _inventoryWidget;
};
