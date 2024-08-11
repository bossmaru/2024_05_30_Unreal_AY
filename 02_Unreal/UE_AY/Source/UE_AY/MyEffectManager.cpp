// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffectManager.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
// #include "Engine/World.h"

// Sets default values
AMyEffectManager::AMyEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CreateParticle("P_Wukong_GreatSage_DJO_Radius", "/Script/Engine.ParticleSystem'/Game/ParagonSunWukong/FX/Particles/Wukong/Skins/GreatSage/FX/P_Wukong_GreatSage_DJO_Radius.P_Wukong_GreatSage_DJO_Radius'");
}

void AMyEffectManager::CreateParticle(FString name, FString path)
{
	// FText text = FText::FromString(path);
	static ConstructorHelpers::FObjectFinder<UParticleSystem> explosion(*path);
	if (explosion.Succeeded())
	{
		for (int i = 0; i < _poolCount; i++)
		{
			UParticleSystem* particle = explosion.Object;
			_table.Add(name, particle);
		}
	}
}

// Called when the game starts or when spawned
void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffectManager::Play(FString name, FVector location, FRotator rotator)
{
	if (_table.Contains(name) == false)
		return;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _table[name], location, rotator);
}
