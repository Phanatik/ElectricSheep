// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HUD/ES_HUDBase.h"
#include "Player/ES_PlayerCharacterBase.h"
#include "ES_PlayerControllerBase.generated.h"

class UInputComponent;
/**
 * 
 */
UCLASS()
class ELECTRICSHEEP_API AES_PlayerControllerBase : public APlayerController
{

	GENERATED_BODY()

	AES_PlayerControllerBase();
public:
	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles strafing movement, left and right */
	void MoveRight(float Val);

	void Jump();

	void StopJumping();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	void AddControllerYawInput(float Val);

	void AddControllerPitchInput(float Val);

protected:
	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	virtual void SetupInputComponent() override;
};
