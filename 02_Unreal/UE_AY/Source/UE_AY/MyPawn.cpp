// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_sm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	RootComponent = _sm;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (mesh.Succeeded())
	{
		_sm->SetStaticMesh(mesh.Object);
	}
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// delegate : 대리자... 함수포인터, 함수객체 -> CallAble, 콜백함수
	// PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	// PlayerInputComponent->BindAxis(TEXT("RightLeft"), this, &AMyPawn::RightLeft);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);

		// Looking
		EnhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyPawn::Look);
	}
}

void AMyPawn::Move(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyPawn::Look(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMyPawn::UpDown(float value)
{
	if (abs(value) >= 0.01)
	{
		// UE_LOG(LogTemp, Log, TEXT("UpDown : %f"), value);
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, value);
	}
}

void AMyPawn::RightLeft(float value)
{
	if (abs(value) >= 0.01)
	{
		// UE_LOG(LogTemp, Log, TEXT("RightLeft : %f"), value);
		FVector right = GetActorRightVector();
		AddMovementInput(right, value);
	}
}

