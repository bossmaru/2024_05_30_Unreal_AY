// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

#include "NiagaraSystem.h"
#include "NiagaraComponent.h"

// Sets default values
AMyEffect::AMyEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Actor -> SpawnWorld
	// Component -> CreateDefaultSubObject
	// UObject -> NewObject<T> (잘 안씀) -> 프로그래머가 직접 지워줘야함

	_particleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	// ->SetupAttachment(RootComponent
	RootComponent = _particleComponent;

	_niagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara"));
	_niagaraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyEffect::BeginPlay()
{
	Super::BeginPlay();
	
	// 원래는 분리해야함 (MyEffect 하위에 상속하든지...)
	_particleComponent->OnSystemFinished.AddDynamic(this, &AMyEffect::End);
	End(_particleComponent);

	_niagaraComponent->OnSystemFinished.AddDynamic(this, &AMyEffect::EndNiagara);
	EndNiagara(_niagaraComponent);
}

// Called every frame
void AMyEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffect::Play(FVector location, FRotator rotator)
{
	if (_particleComponent->IsActive() || _niagaraComponent->IsActive())
		return;

	SetActorLocationAndRotation(location, rotator);
	_particleComponent->ActivateSystem();
	_niagaraComponent->ActivateSystem();
}

bool AMyEffect::IsPlaying()
{
	if (_particleComponent->IsActive() )
		return true;

	if (_niagaraComponent->IsActive())
		return true;
	else
		return false;
}

void AMyEffect::End(UParticleSystemComponent* particle)
{
	if(particle)
		particle->DeactivateSystem();
}

void AMyEffect::EndNiagara(UNiagaraComponent* niagara)
{
	if (niagara)
		niagara->Deactivate();
}

