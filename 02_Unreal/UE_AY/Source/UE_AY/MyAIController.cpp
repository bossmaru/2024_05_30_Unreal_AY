// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MyMonster.h"

AMyAIController::AMyAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData>  BB (TEXT("/Script/AIModule.BlackboardData'/Game/BluePrint/AI/MonsterBB_BP.MonsterBB_BP'"));
	static ConstructorHelpers::FObjectFinder<UBehaviorTree>  BT (TEXT("/Script/AIModule.BehaviorTree'/Game/BluePrint/AI/MonsterBT_BP.MonsterBT_BP'"));

	if (BB.Succeeded())
	{
		_bb = BB.Object;
	}

	if (BT.Succeeded())
	{
		_bt = BT.Object;
	}
}

// 컨트롤러가 폰에 빙의하는 것을 Possess
void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	_startPos = InPawn->GetActorLocation();

	// GetWorld()->GetTimerManager().SetTimer(_timerHandle, this, &AMyAIController::RandMove, 3.0f, true);

	UBlackboardComponent* blackBoardComponent = Blackboard;
	if (UseBlackboard(_bb, blackBoardComponent))
	{
		if (RunBehaviorTree(_bt))
		{
			blackBoardComponent->SetValueAsVector(FName(TEXT("FixedPos")), InPawn->GetActorLocation());
			UE_LOG(LogTemp, Log, TEXT("Behavior Tree Succeeded"));
		}
	}

	auto monster = Cast<AMyMonster>(InPawn);
	monster->_statComponent->_deathDelegate.AddUObject(this, &AMyAIController::UnPossess);
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	// GetWorld()->GetTimerManager().ClearTimer(_timerHandle);
}

void AMyAIController::Tick(float DeltaTime)
{
	// DrawDebugSphere(GetWorld(), _startPos, 500.0f, 32, FColor::Red, false, 0.3f);
}

void AMyAIController::RandMove()
{
	auto currentPawn = GetPawn();

	if (currentPawn->IsValidLowLevel() == false)
		return;

	auto naviSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (naviSystem == nullptr)
		return;

	FNavLocation randLocation;
	if (naviSystem->GetRandomPointInNavigableRadius(currentPawn->GetActorLocation(), 500.0f, randLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, randLocation);
	}
}
