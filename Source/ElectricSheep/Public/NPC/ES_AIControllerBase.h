// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ES_AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ELECTRICSHEEP_API AES_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:


    void StartDialogue();
};
