// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyCharacter.h"
#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/Button.h"
#include "MyInventory.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"

AMyGameModeBase::AMyGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMyCharacter>
		myCharacter(TEXT("/Script/Engine.Blueprint'/Game/BluePrint/Player/MyCharacter_BP.MyCharacter_BP_C'"));

	if (myCharacter.Succeeded())
	{
		DefaultPawnClass = myCharacter.Class;
	}

	static ConstructorHelpers::FClassFinder<AMyCharacter>
		myMonster(TEXT("/Script/Engine.Blueprint'/Game/BluePrint/Player/MyMonster_BP.MyMonster_BP_C'"));

	if (myMonster.Succeeded())
	{
		_monsterClass = myMonster.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> inventory(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/MyInventory_BP.MyInventory_BP_C'"));
	if (inventory.Succeeded())
	{
		_inventoryWidgetClass = inventory.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Inventory Widget class"));
	}
}

void AMyGameModeBase::BeginPlay()
{
	SpawnMonsters();
	SetInventoryWidget();
}

void AMyGameModeBase::SpawnMonsters()
{
	FVector location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() + FVector(100, 0.0f, 0.0f);
	FRotator rotator = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();

	for (int i = 0; i < 3; i++)
	{
		location.X += 300.0f;
		location.Z += 300.0f;
		AMyCharacter* monster = GetWorld()->SpawnActor<AMyCharacter>(_monsterClass, location, rotator);
		_monsters.Add(monster);
	}
}

void AMyGameModeBase::SetInventoryWidget()
{
	if (_inventoryWidgetClass)
	{
		_inventoryWidget = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), _inventoryWidgetClass);
		if (_inventoryWidget)
		{
			_inventoryWidget->AddToViewport();
			_inventoryWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}
