// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffectManager.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "MyEffect.h"
// #include "Engine/World.h"

// Sets default values
AMyEffectManager::AMyEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CreateParticleClass(TEXT("Explosion"), TEXT("/Script/Engine.Blueprint'/Game/BluePrint/VFX/MyEffect_BP.MyEffect_BP_C'"));
}

void AMyEffectManager::CreateParticleClass(FString name, FString path)
{
	// FText text = FText::FromString(path);
	// static ConstructorHelpers::FObjectFinder<UParticleSystem> explosion(*path);
	// if (explosion.Succeeded())
	// {
	// 	for (int i = 0; i < _poolCount; i++)
	// 	{
	// 		UParticleSystem* particle = explosion.Object;
	// 		_table.Add(name, particle);
	// 	}
	// }

	if (_classTable.Contains(name) == true)
	{
		UE_LOG(LogTemp, Error, TEXT("%s already exist in  classTable"), *name);
		return;
	}

	static ConstructorHelpers::FClassFinder<AMyEffect> effect(*path);

	if (effect.Succeeded())
	{
		_classTable.Add(name);
		_classTable[name] = effect.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("can't find %s"), *path);
		return;
	}
}

// Called when the game starts or when spawned
void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();

	CreateEffect();
	
	// _myEffect = GetWorld()->SpawnActor<AMyEffect>(_myEffectClass, FVector::ZeroVector, FRotator::ZeroRotator);
}

void AMyEffectManager::CreateEffect()
{
	for (auto classPair : _classTable)
	{
		FString name = classPair.Key;
		_effectTable.Add(name);
		for (int i = 0; i < _poolCount; i++)
		{
			auto effect = GetWorld()->SpawnActor<AMyEffect>(classPair.Value, FVector::ZeroVector, FRotator::ZeroRotator);
			// effect->SetOwner(this);
			
			effect->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			_effectTable[name].Add(effect);
		}
	}
}

// Called every frame
void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffectManager::Play(FString name, FVector location, FRotator rotator)
{
	// if (_table.Contains(name) == false)
	// 	return;
	// 
	// // UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _table[name], location, rotator);
	// _myEffect->Play(location, rotator);


	if (_effectTable.Contains(name) == false)
		return;

	auto findEffect = _effectTable[name].FindByPredicate([](AMyEffect* effect)->bool
		{
			if (effect->IsPlaying())
				return false;
			return true;
		});

	if(*findEffect)
		(*findEffect)->Play(location, rotator);

	// for (auto effect : _effectTable[name])
	// {
	// 	if (effect->IsPlaying())
	// 		continue;
	// 	effect->Play(location, rotator);
	// 	break;
	// }



	// Actor Component : inventory compoenent, stat component
	// Scene Component : camera, spring arm, mesh, 
}
