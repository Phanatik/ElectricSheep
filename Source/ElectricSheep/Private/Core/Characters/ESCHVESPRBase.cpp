// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Characters/ESCHVESPRBase.h"
#include "Core/PlayerController/ESPCVESPRBase.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"


// Sets default values
AESCHVESPRBase::AESCHVESPRBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("VESPRCamera"));
	Camera->SetupAttachment(RootComponent);


	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioC"));
	AudioComp->SetupAttachment(Camera);

	this->GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	this->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	this->GetCharacterMovement()->GravityScale = 0.0f;



	static ConstructorHelpers::FObjectFinder<USoundCue> VESPRCue(TEXT("'/Game/ElectricSheep/Characters/VESPR/Audio/Cues/S_VESPR.S_VESPR'"));
	VESPRAudioCue = VESPRCue.Object;
	AudioComp->SetSound(VESPRAudioCue);

	InputScale = 50.0f;
	Step = 0;
	Stutters = 5;
}

// Called when the game starts or when spawned
void AESCHVESPRBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AESCHVESPRBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AESCHVESPRBase::SetAudioAndPlay(int CueIndex, bool PlayCue)
{
	AudioComp->SetIntParameter("Started", CueIndex);
	if (PlayCue){
		AudioComp->Play(0.0f);
	}
}

void AESCHVESPRBase::OnAudioFinished()
{
	if (Step == Stutters)
	{
		Step = 0;
		AudioComp->OnAudioFinished.RemoveDynamic(this, &AESCHVESPRBase::OnAudioFinished);
		SetAudioAndPlay(3, true);
		this->EnableInput(MyPlayerController);
	}
	else
	{
		Step += 1;
		this->ProcessMovement();
	}
}

void AESCHVESPRBase::ProcessMovement()
{
	MyPlayerController = Cast<AESPCVESPRBase>(this->GetController());
	for (int i = Step; i < Step+1; i++)
	{
		FVector NewVector = (i * StutterStep) + CurrentLocation;
		Camera->SetWorldLocation(NewVector, true);
		AudioComp->Play();
	}
	MyPlayerController->ResetPlayerMoving();
}

void AESCHVESPRBase::MoveVESPR(FVector InputVector, float InputValue)
{
	this->DisableInput(MyPlayerController);

	Offset = (InputValue * InputScale) * InputVector;
	StutterStep = Offset/Stutters;

	CurrentLocation = Camera->GetComponentLocation();

	SetAudioAndPlay(5, true);
	SetAudioAndPlay(1, false);

	AudioComp->OnAudioFinished.AddDynamic(this, &AESCHVESPRBase::OnAudioFinished);
	this->ProcessMovement();
}
