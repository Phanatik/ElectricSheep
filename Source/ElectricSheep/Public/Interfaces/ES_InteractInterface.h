// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UObject/Interface.h"
#include "ES_InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UES_InteractInterface : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class ELECTRICSHEEP_API IES_InteractInterface
{
    GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Trigger)
    void StartInteract(ACharacter* character);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Trigger)
    void EndInteract();
	
};
