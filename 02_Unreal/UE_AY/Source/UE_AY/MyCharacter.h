// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyStatComponent.h"
#include "MyCharacter.generated.h" // generate는 맨 아래

class UInputComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_MULTICAST_DELEGATE(AttackEndedDelegate);

DECLARE_MULTICAST_DELEGATE(ViewInventoryDelegate);
DECLARE_MULTICAST_DELEGATE(AddItemToInventory);
DECLARE_MULTICAST_DELEGATE(DropItemFromInventory);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackHitEventDelegate);

UCLASS()
class UE_AY_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	virtual void Init();

	UFUNCTION()
	virtual void Disable();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
	void OnAttackEnded(class UAnimMontage* Montage, bool binterrupted);

	UFUNCTION()
	void AttackHit();

	int GetCurHp() { return _statComponent->GetHp(); }

	void AddAttackDamage(AActor* actor, int amount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	bool _tryGetItem = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	bool _isAttacking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	int _curAttackIndex = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float _vertical = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float _horizontal = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AttackHit, meta = (AllowPrivateAccess = "true"))
	FVector _hitPoint;

	// Animation
	class UMyAnimInstance* _animInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UMyStatComponent* _statComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* _hpBarWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class AAIController* _aiController;

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Niagara, meta = (AllowPrivateAccess = "true"))
	// class UNiagaraSystem* _vfx;

	// Stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat, meta = (AllowPrivateAccess = "true"))
	int32 _level = 1;

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Particle, meta = (AllowPrivateAccess = "true"))
	// class UParticleSystem* _particle;
	
	AttackEndedDelegate _attackEndedDelegate;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = Event, meta = (AllowPrivateAccess = "true"))
	FAttackHitEventDelegate _attackHitEventDelegate;

	ViewInventoryDelegate _viewInventoryDelegate;
	AddItemToInventory _addItemToInventoryDelegate;
	DropItemFromInventory _dropItemFromInventoryDelegate;
};
