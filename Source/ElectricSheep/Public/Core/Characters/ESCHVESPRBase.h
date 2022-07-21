// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "ESCHVESPRBase.generated.h"

UCLASS()
class ELECTRICSHEEP_API AESCHVESPRBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AESCHVESPRBase();

	float InputScale;
	int Step;
	int Stutters;

	FVector StutterStep;
	FVector Offset;
	FVector CurrentLocation;

	USoundCue* VESPRAudioCue;

	APlayerController* MyPlayerController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category="Components")
	USceneCaptureComponent2D* Camera;

	UPROPERTY(VisibleAnywhere,Category="Components")
	UAudioComponent* AudioComp;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveVESPR(FVector InputVector, float InputValue);

	void SetAudioAndPlay(int CueIndex, bool PlayCue);

	void OnAudioFinished();

	void ProcessMovement();
	
};
