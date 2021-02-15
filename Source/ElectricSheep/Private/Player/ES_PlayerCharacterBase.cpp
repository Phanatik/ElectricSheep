// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ES_PlayerCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/ES_PlayerControllerBase.h"
#include "Components/InputComponent.h"
#include "Blueprint/WidgetTree.h"
#include "Components/WidgetInteractionComponent.h"

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

    InteractBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractBoxCollider->SetupAttachment(FirstPersonCameraComponent);
    InteractBoxCollider->SetRelativeLocation(FVector(50.f, 0, 0.f)); // Position the camera
    InteractBoxCollider->InitBoxExtent(FVector(60.f,60.f,30.f));
    InteractBoxCollider->ComponentTags.Add(FName("Character"));

    //WidgetIntComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInt"));
    //WidgetIntComponent->SetupAttachment(FirstPersonCameraComponent);
    //WidgetIntComponent->SetRelativeLocation(FVector(0, 0, 0)); // Position the camera
    //WidgetIntComponent->InteractionSource = EWidgetInteractionSource[0];
}

// Called when the game starts or when spawned
void AES_PlayerCharacterBase::BeginPlay()
{
    Super::BeginPlay();


}

void AES_PlayerCharacterBase::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
    if (HitComp)
    {
        if(HitComp->ComponentHasTag(FName("NPC")))
        {
            //StartInteract_Implementation();
        }
    }
}

// Called every frame
void AES_PlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AES_PlayerCharacterBase::StartInteract_Implementation(ACharacter* character)
{

}



void AES_PlayerCharacterBase::EndInteract_Implementation()
{

}
