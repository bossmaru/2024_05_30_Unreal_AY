// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Controller.h"
#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "MyHpBar.h"
#include "MyInventory.h"
#include "MyGameModeBase.h"
#include "MyItem.h"
#include "MyAIController.h"
#include "MyEffectManager.h"
#include "MyGameInstance.h"

// #include "NiagaraComponent.h"
// #include "NiagaraFunctionLibrary.h"

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

	APawn::AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// static ConstructorHelpers::FObjectFinder<UParticleSystem> pt(TEXT("/Script/Engine.ParticleSystem'/Game/ParagonSunWukong/FX/Particles/Wukong/Skins/GreatSage/FX/P_Wukong_GreatSage_DJE_CloudBurst.P_Wukong_GreatSage_DJE_CloudBurst'"));
	// if (pt.Succeeded())
	// {
	// 	_particle = pt.Object;
	// }

	// static ConstructorHelpers::FObjectFinder<UNiagaraSystem> vfx(TEXT("/Script/Niagara.NiagaraSystem'/Game/MegaMagicVFXBundle/VFX/MagicalExplosionsVFX/VFX/MagicalExplosion/Systems/N_MagicalExplosion.N_MagicalExplosion'"));
	// if (vfx.Succeeded())
	// {
	// 	_vfx = vfx.Object;
	// }
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Init();

	// UNiagaraComponent* nc = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), _vfx, GetActorLocation());
	// UNiagaraComponent* nc = UNiagaraFunctionLibrary::SpawnSystemAttached(_vfx, _statComponent, NAME_None, GetActorLocation(), FRotator::ZeroRotator, EAttachLocation::Type::KeepWorldPosition, true);

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
	_attackEndedDelegate.Broadcast();
}

void AMyCharacter::AttackHit()
{
	FHitResult hitResult;

	// 나는 무시해라
	FCollisionQueryParams params (NAME_None, false, this);
	float attackRange = 1000.0f;
	float attackRadius = 30.0f;
	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);
	// FQuat quat = FRotationMatrix::MakeFromZ(forward).ToQuat();

	FVector center = GetActorLocation() + forward * attackRange * 0.5f;
	FVector start = GetActorLocation() + attackRange;
	FVector end = GetActorLocation() + forward * attackRange;

	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		start,
		end,
		// FQuat::Identity,
		quat,
		ECollisionChannel::ECC_GameTraceChannel2,
		// FCollisionShape::MakeSphere(attackRadius),
		FCollisionShape::MakeCapsule(attackRadius, attackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		AMyCharacter* target = Cast<AMyCharacter>(hitResult.GetActor());
		if (target)
		{
			FDamageEvent damageEvent;
			hitResult.GetActor()->TakeDamage(_statComponent->GetAttackDamage(), damageEvent, GetController(), this);
			_hitPoint = hitResult.ImpactPoint;
			EffectManager->Play("P_Wukong_GreatSage_DJO_Radius", _hitPoint);
			// _attackHitEventDelegate.Broadcast();

			DrawDebugCapsule(GetWorld(), center, attackRange * 0.5f, attackRadius, quat, FColor::Red, false, 2.0f);
		}
		// hitPoint.Z /= 4;
		// if (_particle)
		// {
		// 	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _particle, hitPoint, FRotator::ZeroRotator);
		// }

		// drawColor = FColor::Red;

		else
		{
			DrawDebugCapsule(GetWorld(), center, attackRange * 0.5f, attackRadius, quat, FColor::Green, false, 2.0f);
		}
	}

	else
		DrawDebugCapsule(GetWorld(), center, attackRange * 0.5f, attackRadius, quat, FColor::Green, false, 2.0f);
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

	if (_aiController && GetController() == nullptr)
	{
		_aiController->Possess(this);
	}
}

void AMyCharacter::Disable()
{
	SetActorHiddenInGame(true); // 액터를 게임에서 숨깁니다.
	SetActorEnableCollision(false); // 충돌 비활성화
	// SetActorTickEnabled(false); // Tick 비활성화
	PrimaryActorTick.bCanEverTick = false;

	auto controller = GetController();
	if (controller)
	{
		GetController()->UnPossess();
	}
}

