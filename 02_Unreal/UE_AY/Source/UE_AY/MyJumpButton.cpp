// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJumpButton.h"
#include "MyCharacter.h"
#include "Components/Button.h"

void UMyJumpButton::NativeConstruct()
{
    Super::NativeConstruct();

    if (JumpButton)
    {
        JumpButton->OnClicked.AddDynamic(this, &UMyJumpButton::JumpButtonClicked);
    }
}

void UMyJumpButton::JumpButtonClicked()
{
    AMyCharacter* player = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if (player)
    {
        player->Jump();
    }
}
