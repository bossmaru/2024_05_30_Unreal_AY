// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInventory.h"

void UMyInventory::ToggleVisiblity()
{
	if (_isVisible)
	{
		this->SetVisibility(ESlateVisibility::Hidden);
		_isVisible = false;
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Visible);
		_isVisible = true;
	}
}
