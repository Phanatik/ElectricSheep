// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/ES_NPCProfile.h"

// Sets default values
AES_NPCProfile::AES_NPCProfile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    //PrimaryActorTick.bCanEverTick = true;

    InteractBoxCollider->ComponentTags.Add(FName("NPC"));
}

// Called when the game starts or when spawned
void AES_NPCProfile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AES_NPCProfile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

