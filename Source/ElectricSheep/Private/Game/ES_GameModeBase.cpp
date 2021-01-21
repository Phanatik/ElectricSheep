// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ES_GameModeBase.h"
#include "Player/ES_PlayerControllerBase.h"
#include "Player/ES_PlayerCharacterBase.h"
#include "Game/ES_GameStateBase.h"
#include "Game/ES_PawnBase.h"

AES_GameModeBase::AES_GameModeBase()
{
	PlayerControllerClass = AES_PlayerControllerBase::StaticClass();
	GameStateClass = AES_GameStateBase::StaticClass();
	DefaultPawnClass = AES_PlayerCharacterBase::StaticClass();
}