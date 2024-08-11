// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUIManager.h"
#include "MyInventory.h"

// Sets default values
AMyUIManager::AMyUIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUserWidget> inventoryClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/MyInventory_BP.MyInventory_BP_C'"));
	if (inventoryClass.Succeeded())
	{
		auto temp = inventoryClass.Class;
		_inventoryWidget = CreateWidget<UMyInventory>(GetWorld(), temp);
	}
}

// Called when the game starts or when spawned
void AMyUIManager::BeginPlay()
{
	Super::BeginPlay();
	
	_inventoryWidget->AddToViewport();
	_inventoryWidget->SetVisibility(ESlateVisibility::Hidden);
}

// Called every frame
void AMyUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

