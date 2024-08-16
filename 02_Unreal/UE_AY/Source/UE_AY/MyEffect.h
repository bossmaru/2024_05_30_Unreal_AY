// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEffect.generated.h"

UCLASS()
class UE_AY_API AMyEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Play(FVector location, FRotator rotator);

	bool IsPlaying();

	UFUNCTION()
	void End(class UParticleSystemComponent* particle);

	UFUNCTION()
	void EndNiagara(class UNiagaraComponent* niagara);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* _particleComponent;

	// 나이아가라...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* _niagaraComponent;

};
