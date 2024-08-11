// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE_AY_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMyAIController();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	virtual void Tick(float DeltaTime) override;

	void RandMove();

	FVector GetStartPos() { return _startPos; };

private:
	FTimerHandle _timerHandle;
	
	UPROPERTY()
	class UBlackboardData* _bb;
	UPROPERTY()
	class UBehaviorTree* _bt;

	FVector _startPos;
};
