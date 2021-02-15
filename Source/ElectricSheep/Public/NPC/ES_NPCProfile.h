// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/ES_PlayerCharacterBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "ES_NPCProfile.generated.h"

UCLASS()
class ELECTRICSHEEP_API AES_NPCProfile : public AES_PlayerCharacterBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AES_NPCProfile();

protected:    
    /** First person camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Interaction, meta = (AllowPrivateAccess = "true"))
    UBehaviorTree* DialogueTree;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
