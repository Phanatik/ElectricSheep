// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PlayerController/ESPCVESPRBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Core/Characters/ESCHVESPRBase.h"


void AESPCVESPRBase::BeginPlay()
{
	Super::BeginPlay();
    PlayerObject = Cast<AESCHVESPRBase>(this->GetCharacter());
    bPlayerMoving = false;
}

void AESPCVESPRBase::ResetPlayerMoving()
{
    bPlayerMoving = false;
}

void AESPCVESPRBase::LookUpDown(float axisvalue)
{
    if (axisvalue != 0.0f)
    {
        if (PlayerObject)
        {
            if (!bPlayerMoving)
            {
                PlayerObject->MoveVESPR(PlayerObject->GetActorUpVector(), axisvalue);
                bPlayerMoving = true;
            }
        }
    }
}

void AESPCVESPRBase::MoveForwardBackward(float axisvalue)
{
    if (axisvalue != 0.0f)
    {
        if (PlayerObject)
        {
            PlayerObject->MoveVESPR(PlayerObject->GetActorForwardVector(), axisvalue);
        }
    }
}

void AESPCVESPRBase::MoveRightLeft(float axisvalue)
{
    if (axisvalue != 0.0f)
    {
        if (PlayerObject)
        {
            if (!bPlayerMoving)
            {
                bPlayerMoving = true;
                PlayerObject->MoveVESPR(PlayerObject->GetActorRightVector(), axisvalue);
            }
        }
    }
}

void AESPCVESPRBase::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis(TEXT("LookUpDown"),this,&AESPCVESPRBase::LookUpDown);
    InputComponent->BindAxis(TEXT("MoveForwardBackward"),this,&AESPCVESPRBase::MoveForwardBackward);
    InputComponent->BindAxis(TEXT("MoveRightLeft"),this,&AESPCVESPRBase::MoveRightLeft);
}
