// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ES_PlayerControllerBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Game/ES_PawnBase.h"
#include "Player/ES_PlayerCharacterBase.h"
#include "GameFramework/Pawn.h"

AES_PlayerControllerBase::AES_PlayerControllerBase()
{
	// Set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

    //Default Interact boolean to false
    CanInteract = false;

}

void AES_PlayerControllerBase::BeginPlay()
{

}

void AES_PlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed, this, &AES_PlayerControllerBase::Jump);
    InputComponent->BindAction("Jump", IE_Released, this, &AES_PlayerControllerBase::StopJumping);
    InputComponent->BindAction("Fire", IE_Pressed, this, &AES_PlayerControllerBase::StartFiring);
    InputComponent->BindAction("Fire", IE_Released, this, &AES_PlayerControllerBase::StopFiring);
	InputComponent->BindAxis("MoveForward", this, &AES_PlayerControllerBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AES_PlayerControllerBase::MoveRight);
	InputComponent->BindAxis("Turn", this, &AES_PlayerControllerBase::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AES_PlayerControllerBase::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AES_PlayerControllerBase::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AES_PlayerControllerBase::LookUpAtRate);
}


void AES_PlayerControllerBase::MoveForward(float Val)
{
	if (Val != 0.0f)
    {
        auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
		// Add movement in that direction
		if (pawn)
		{
			pawn->AddMovementInput(pawn->GetActorForwardVector(), Val);
		}
	}
    InteractCheck();
}

void AES_PlayerControllerBase::MoveRight(float Val)
{
	if (Val != 0.0f)
    {
        auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
		// Add movement in that direction
		if (pawn)
		{
			pawn->AddMovementInput(pawn->GetActorRightVector(), Val);
		}
	}
}

void AES_PlayerControllerBase::Jump()
{
}

void AES_PlayerControllerBase::StopJumping()
{
}

void AES_PlayerControllerBase::AddControllerYawInput(float Val)
{
	if (Val != 0.0f)
    {
        auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
		// Add movement in that direction
		if (pawn)
		{
			pawn->AddControllerYawInput(Val);
		}
	}
}

void AES_PlayerControllerBase::AddControllerPitchInput(float Val)
{
	if (Val != 0.0f)
    {
        auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
		// Add movement in that direction
		if (pawn)
		{
			pawn->AddControllerPitchInput(Val);
		}
	}
}

void AES_PlayerControllerBase::TurnAtRate(float Rate)
{
    // Calculate delta for this frame from the rate information
    auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
	// Add movement in that direction
	if (pawn)
	{
		pawn->AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void AES_PlayerControllerBase::LookUpAtRate(float Rate)
{
    // Calculate delta for this frame from the rate information
    auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
	if (pawn)
	{
		pawn->AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
	}
}

void AES_PlayerControllerBase::StartFiring()
{
    auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
    if (pawn)
    {
        //pawn->WidgetIntComponent->PressPointerKey(EKeys::LeftMouseButton);
    }

}


void AES_PlayerControllerBase::StopFiring()
{
    auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
    if (pawn)
    {
        //pawn->WidgetIntComponent->ReleasePointerKey(EKeys::LeftMouseButton);
    }

}

void AES_PlayerControllerBase::InteractCheck()
{
    auto pawn = Cast<AES_PlayerCharacterBase>(this->GetPawn());
    if (pawn)
    {
        //pawn->InteractBoxCollider->OnComponentHit.AddDynamic(pawn, &AES_PlayerCharacterBase::OnHit);

    }
    //Get Interactable objects, check to see if any in close proximity to player
    //If object close to player, then display Interact UI
    //Would apply to all objects including NPCs in order to engage dialogue and in-world interactable objects like vending machines
}
