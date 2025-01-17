// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Service_FindTarget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MyAIController.h"
#include "MyPlayer.h"
#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"

UBT_Service_FindTarget::UBT_Service_FindTarget()
{
	NodeName = TEXT("FindTarget");
	Interval = 0.5f;
}

void UBT_Service_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (currentPawn == nullptr)
		return;

	auto world = GetWorld();
	FVector center = currentPawn->GetActorLocation();
	float searchRadius = 500.0f;

	if (world == nullptr)
		return;
	
	TArray<FOverlapResult> overlapResult;
	FCollisionQueryParams qparams (NAME_None, false, currentPawn);
	bool bResult = world->OverlapMultiByChannel
	(
		overlapResult,
		center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(searchRadius),
		qparams
	);

	if (bResult)
	{
		for (auto& result : overlapResult)
		{
			
			auto myCharacter = Cast<AMyPlayer>(result.GetActor());

			if (myCharacter != nullptr)
			{
				if (myCharacter->GetController() != nullptr && myCharacter->GetController()->IsPlayerController())
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), myCharacter);
					// DrawDebugSphere(world, center, searchRadius, 32, FColor::Red, false, 0.3f);

					return;
				}
			}
		}

		// DrawDebugSphere(world, center, searchRadius, 32, FColor::Green, false, 0.3f);
	}

	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
		// DrawDebugSphere(world, center, searchRadius, 32, FColor::Green, false, 0.3f);
	}
}
