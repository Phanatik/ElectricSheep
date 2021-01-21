// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ES_PlayerCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/ES_PlayerControllerBase.h"
#include "Components/InputComponent.h"

// Sets default values
AES_PlayerCharacterBase::AES_PlayerCharacterBase()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(0, 0, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AES_PlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AES_PlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
