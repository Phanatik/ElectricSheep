// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/Characters/ESCHVESPRBase.h"
#include "ESPCVESPRBase.generated.h"


class UInputComponent;
/**
 * 
 */
UCLASS(config=Game)
class ELECTRICSHEEP_API AESPCVESPRBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	bool bPlayerMoving;
	AESCHVESPRBase* PlayerObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	void LookUpDown(float axisvalue);
	void MoveForwardBackward(float axisvalue);
	void MoveRightLeft(float axisvalue);

	void ResetPlayerMoving();
};
