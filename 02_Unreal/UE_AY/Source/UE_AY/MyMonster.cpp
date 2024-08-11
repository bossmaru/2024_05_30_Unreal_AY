// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMonster.h"
#include "MyAIController.h"
#include "MyAnimInstance.h"

void AMyMonster::BeginPlay()
{
	Super::BeginPlay();

	_aiController = Cast<AMyAIController>(GetController());
	// bUseControllerRotationYaw = true;
}

void AMyMonster::Attack_AI()
{
	if (_statComponent->IsDead())
		return;
	if (_isAttacking == false && _animInstance != nullptr)
	{
		_animInstance->PlayAttackMontage();
		_isAttacking = true;

		_curAttackIndex %= 3;
		_curAttackIndex++;
		_animInstance->JumpToSection(_curAttackIndex);
	}
}
