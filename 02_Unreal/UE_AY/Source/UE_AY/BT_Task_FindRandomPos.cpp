// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_FindRandomPos.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIController.h"
#include "MyAIController.h"

UBT_Task_FindRandomPos::UBT_Task_FindRandomPos()
{
	NodeName = TEXT("FindRandPos");
}

EBTNodeResult::Type UBT_Task_FindRandomPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (currentPawn->IsValidLowLevel() == false)
		return EBTNodeResult::Type::Failed;

	auto naviSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (naviSystem == nullptr)
		return EBTNodeResult::Type::Failed;

	FNavLocation randLocation;

	// FVector startPos = Cast<AMyAIController>(OwnerComp.GetAIOwner())->GetStartPos();
	FVector fixedPos = OwnerComp.GetBlackboardComponent()->GetValueAsVector(FName(TEXT("FixedPos")));

	if (naviSystem->GetRandomPointInNavigableRadius(fixedPos, 500.0f, randLocation))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandPos")), randLocation);

		return EBTNodeResult::Type::Succeeded;
	}

	return result;
}
