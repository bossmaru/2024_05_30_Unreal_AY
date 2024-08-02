// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyAnimInstance.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Controller.h"
#include "MyInventoryComponent.h"
#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "MyHpBar.h"
#include "MyInventory.h"
#include "MyGameModeBase.h"
#include "MyItem.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TODO
	// Skeletal Mesh
	// / Script / Engine.SkeletalMesh'/Game/ParagonSunWukong/Characters/Heroes/Wukong/Meshes/Wukong.Wukong'
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> sm
	(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSunWukong/Characters/Heroes/Wukong/Meshes/Wukong.Wukong'"));

	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// 상속관계 설정
	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

	_inventoryComponent = CreateDefaultSubobject<UMyInventoryComponent>(TEXT("InventoryComponent"));

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("StatComponent"));

	_hpBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBar"));
	_hpBarWidget->SetupAttachment(GetMesh());
	_hpBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	_hpBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 200.0f));

	static ConstructorHelpers::FClassFinder<UUserWidget> hpBar(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/MyHpBar_BP.MyHpBar_BP_C'"));

	if (hpBar.Succeeded())
	{
		_hpBarWidget->SetWidgetClass(hpBar.Class);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void AMyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());

	if (_animInstance->IsValidLowLevel())
	{
		// 몽타주가 끝날 때 _isAttack을 False로 만들어줬으면 좋겠다.
		_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackEnded);
		_animInstance->_attackDelegate.AddUObject(this, &AMyCharacter::AttackHit);
		_animInstance->_deathDelegate.AddUObject(this, &AMyCharacter::Disable);
	}

	_gameModeBase = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());

	_statComponent->SetLevelAndInit(_level);

	_hpBarWidget->InitWidget();
	auto hpBar = Cast<UMyHpBar>(_hpBarWidget->GetUserWidgetObject());
	if (hpBar)
	{
		_statComponent->_hpChangedDelegate.AddUObject(hpBar, &UMyHpBar::SetHpBarValue);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// _myDelegate1.ExecuteIfBound();

	// HP : 50, MP : 30
	// 1. Delegate 방법
	// _myDelegate3.ExecuteIfBound(50, 30);

	// 2. 클래스 객체로 직접 함수 호출
	// 단점
	// - 클래스간의 결합도가 높아진다
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);

		// Jumping
		EnhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Started, this, &AMyCharacter::JumpA);

		// Attack
		EnhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyCharacter::AttackA);
		
		// Get Item
		EnhancedInputComponent->BindAction(_getItemAction, ETriggerEvent::Started, this, &AMyCharacter::TryGetItem);
		EnhancedInputComponent->BindAction(_getItemAction, ETriggerEvent::Completed, this, &AMyCharacter::TryGetItemEnd);

		// Drop Item
		EnhancedInputComponent->BindAction(_dropItemAction, ETriggerEvent::Started, this, &AMyCharacter::DropItem);

		// View Inventory
		EnhancedInputComponent->BindAction(_viewInventoryAction, ETriggerEvent::Started, this, &AMyCharacter::ViewInventory);
	}
}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// TODO
	// 1. hp -= damage
	// 2. 공격자 이름 출력

	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	float damaged = _statComponent->AddCurHp(-Damage);

	return -damaged;
}

void AMyCharacter::OnAttackEnded(UAnimMontage* Montage, bool binterrupted)
{
	_isAttacking = false;
}

void AMyCharacter::AttackHit()
{
	FHitResult hitResult;

	// 나는 무시해라
	FCollisionQueryParams params (NAME_None, false, this);
	float attackRange = 500.0f;
	float attackRadius = 50.0f;
	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * attackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(attackRadius),
		params
	);

	FVector vec = GetActorForwardVector() * attackRange;
	// UE_LOG(LogTemp, Log, TEXT("%s"), *vec.ToString());
	FVector center = GetActorLocation() + vec * 0.5f;

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		// TODO
		FDamageEvent damageEvent;
		hitResult.GetActor()->TakeDamage(_statComponent->GetAttackDamage(), damageEvent, GetController(), this);

		drawColor = FColor::Red;
	}

	DrawDebugSphere(GetWorld(), center, attackRadius, 12, drawColor, false, 2.0f);
}

void AMyCharacter::Move(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// add movement 
		_vertical = MovementVector.Y;
		_horizontal = MovementVector.X;


		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMyCharacter::JumpA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed)
	{
		ACharacter::Jump();
	}
}

void AMyCharacter::AttackA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed && _isAttacking == false && _animInstance != nullptr)
	{
		_animInstance->PlayAttackMontage();
		_isAttacking = true;

		_curAttackIndex %= 3;
		_curAttackIndex++;
		_animInstance->JumpToSection(_curAttackIndex);
	}
}

void AMyCharacter::ViewInventory(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed)
	{
		UMyInventory* inventory = Cast<UMyInventory>(_gameModeBase->_inventoryWidget);
		inventory->ToggleVisiblity();
	}
}

void AMyCharacter::TryGetItem(const FInputActionValue& value)
{
	_tryGetItem = true;
}

void AMyCharacter::TryGetItemEnd(const FInputActionValue& value)
{
	_tryGetItem = false;
}

void AMyCharacter::AddItem(AMyItem* item)
{
	_inventoryComponent->AddItem(item);
	_statComponent->AddAttackDamage(30.0f);
}

void AMyCharacter::DropItem(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed)
	{
		_inventoryComponent->DropItem();
		_statComponent->AddAttackDamage(-30.0f);
	}
}

void AMyCharacter::AddAttackDamage(AActor* actor, int amount)
{
	_statComponent->AddAttackDamage(amount);
}

void AMyCharacter::Init()
{
	_statComponent->Reset();
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	// SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacter::Disable()
{
	SetActorHiddenInGame(true); // 액터를 게임에서 숨깁니다.
	SetActorEnableCollision(false); // 충돌 비활성화
	// SetActorTickEnabled(false); // Tick 비활성화
	PrimaryActorTick.bCanEverTick = false;
}

