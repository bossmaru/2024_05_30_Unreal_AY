// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

// USTRUCT()
// struct ItemType
// {
// 
// };
// 
// 
// USTRUCT()
// struct ItemInfo
// {
// 	int itemId;
// 	ItemType type;
// };
// 
UCLASS()
class UE_AY_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnMyCharacterOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void CharacterOverlapped();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* _meshComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;

	UPROPERTY()
	bool _isOverlapped;

	UPROPERTY()
	class AMyPlayer* _player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	class UTexture2D* _itemTexture;

	UPROPERTY(VisibleAnywhere)
	int32 _itemId = -1;
};
