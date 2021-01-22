// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Player/ES_PlayerControllerBase.h"
#include "Player/ES_PlayerCharacterBase.h"
#include "Game/ES_GameStateBase.h"
#include "Game/ES_PawnBase.h"
#include "HUD/ES_HUDBase.h"
#include "ES_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ELECTRICSHEEP_API AES_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	AES_GameModeBase();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HUD")
	TSubclassOf<AES_HUDBase> HUDBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	TSubclassOf<AES_PlayerCharacterBase> CharBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Controller")
	TSubclassOf<AES_PlayerControllerBase> ContBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameState")
	TSubclassOf<AES_GameStateBase> StateBase;

};
