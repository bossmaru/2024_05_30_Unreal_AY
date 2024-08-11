// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"
#include "MyInventoryComponent.h"
#include "MyPlayer.h"

// Sets default values
AMyItem::AMyItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_trigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm
	(TEXT("/Script/Engine.StaticMesh'/Game/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Sickle.SM_Sickle'"));

	if (sm.Succeeded())
	{
		_meshComponent->SetStaticMesh(sm.Object);
	}

	_meshComponent->SetupAttachment(RootComponent);
	_trigger->SetupAttachment(_meshComponent);

	_meshComponent->SetCollisionProfileName(TEXT("MyItem"));
	_trigger->SetCollisionProfileName(TEXT("MyItem"));
	_trigger->SetSphereRadius(60.0f);

	static ConstructorHelpers::FObjectFinder<UTexture2D> tex
	(TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_tools_07.Tex_tools_07'"));

	if (tex.Succeeded())
	{

		_itemTexture = tex.Object;
	}

	_itemTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_tools_07.Tex_tools_07'"));
}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_trigger->OnComponentBeginOverlap.AddDynamic(this, &AMyItem::OnMyCharacterOverlap);
	_trigger->OnComponentEndOverlap.AddDynamic(this, &AMyItem::OnMyCharacterOverlapEnd);
}

void AMyItem::OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_isOverlapped = true;
	_player = Cast<AMyPlayer>(OtherActor);
	// auto myCharacter = Cast<AMyCharacter>(OtherActor);
	// if (myCharacter)
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("%s collision"), *myCharacter->GetName());
	// 	myCharacter->AddItem(this);
	// }
}

void AMyItem::OnMyCharacterOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	_isOverlapped = false;
}

void AMyItem::CharacterOverlapped()
{
	if (_player)
	{
		_player->AddItem(this);
	}
}

// Called every frame
void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_isOverlapped && _player != nullptr)
	{
		if(_player->_tryGetItem)
			CharacterOverlapped();
	}
}

