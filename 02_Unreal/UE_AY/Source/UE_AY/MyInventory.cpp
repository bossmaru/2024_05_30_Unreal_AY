// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventory.h"
#include "Components/UniformGridPanel.h"
#include "Components/Widget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"


void UMyInventory::NativeConstruct()
{
	Super::NativeConstruct();
	SetButtons();
}

void UMyInventory::SetButtons()
{
	TArray<UWidget*> widgets;
	widgets = SlotGrid->GetAllChildren();

	for (UWidget* widget : widgets)
	{
		UButton* button = Cast<UButton>(widget);
		if (button)
		{
			UE_LOG(LogTemp, Warning, TEXT("SetButton"));
			_itemButtons.Add(button);
			_itemButtonImages.Add(Cast<UImage>(button->GetChildAt(0)));
		}
	}

	_default = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_Default.Tex_Default'"));
}

void UMyInventory::ToggleVisiblity()
{
	AMyPlayerController* playerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (_isVisible)
	{
		this->SetVisibility(ESlateVisibility::Hidden);
		_isVisible = false;

		if (playerController != nullptr)
		{
			playerController->HideUI();
		}
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Visible);
		_isVisible = true;

		if (playerController != nullptr)
		{
			playerController->ShowUI();
		}
	}
}

void UMyInventory::SetItemImage(int32 index, UTexture2D* itemImage)
{
	// UTexture2D* itemImage = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_tools_07.Tex_tools_07'"));
	_itemButtonImages[index]->SetBrushFromTexture(itemImage);

	// if (_itemButtonImages.IsEmpty() || !_itemButtonImages.IsValidIndex(index))
	// 	return;
	// 
	// if (index == -1)
	// {
	// 	_itemButtonImages[index]->SetBrushFromTexture(_default);
	// }
	// 
	// else if (index == 11)
	// {
	// 	// _itemButtonImages[index]->SetBrushFromTexture(_default);
	// }

}

void UMyInventory::EraseItemImage()
{
	
}
