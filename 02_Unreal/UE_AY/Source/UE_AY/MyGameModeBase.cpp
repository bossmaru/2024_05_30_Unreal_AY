// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "MyUIManager.h"
#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyCharacter.h"
#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/Button.h"
#include "MyInventory.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "MyInventoryComponent.h"
#include "MyItem.h"
#include "Components/Image.h"
#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "MyAIController.h"


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
}

void AMyGameModeBase::BeginPlay()
{
	SpawnMonsters();

	AMyCharacter* myCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	myCharacter->_viewInventoryDelegate.AddUObject(this, &AMyGameModeBase::ViewInventory);

	myCharacter->_addItemToInventoryDelegate.AddUObject(this, &AMyGameModeBase::AddItemToInventory);
	// myCharacter->_dropItemFromInventoryDelegate.AddUObject(this, &AMyGameModeBase::DropItemFromInventory);

	auto invenUI = UIManager->GetInvenUI();

	// TArray<UImage*> itemImages = inventory->_itemButtonImages;
	// inventory->DropButton->OnClicked.AddDynamic(_inventoryComponent, &UMyInventoryComponent::DropItem);

	// inventory->DropButton->OnClicked.AddDynamic(_inventoryWidget, &UMyInventory::EraseItemImage);
}

void AMyGameModeBase::SpawnMonsters()
{
	FVector location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() + FVector(100, 0.0f, 0.0f);
	FRotator rotator = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();

	// for (int i = 0; i < 3; i++)
	// {
	// 	location.X += 300.0f;
	// 	location.Z += 300.0f;
	// 	AMyCharacter* monster = GetWorld()->SpawnActor<AMyCharacter>(_monsterClass, location, rotator);
	// 
	// 	AMyAIController* aiController = GetWorld()->SpawnActor<AMyAIController>();
	// 	aiController->Possess(monster);
	// 
	// 	_monsters.Add(monster);
	// }
}

void AMyGameModeBase::ViewInventory()
{
	// UMyInventory* inventory = Cast<UMyInventory>(_inventoryWidget);
	// inventory->ToggleVisiblity();

}

void AMyGameModeBase::AddItemToInventory()
{
	// UMyInventory* inventory = Cast<UMyInventory>(_inventoryWidget);
	// TArray<UImage*> itemImages = inventory->_itemButtonImages;
	// TArray<AMyItem*> items = _inventoryComponent->_items;
	// 
	// for (int i = 0; i < items.Num(); i++)
	// {
	// 	AMyItem* item = items[i];
	// 	inventory->SetItemImage(i, item->_itemTexture);
	// }
}

void AMyGameModeBase::DropItemFromInventory()
{
	// UMyInventory* inventory = Cast<UMyInventory>(_inventoryWidget);
	// TArray<UImage*> itemImages = inventory->_itemButtonImages;
}
