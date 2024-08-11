// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyMonster.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API AMyMonster : public AMyCharacter
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	UFUNCTION()
	void Attack_AI();
};
