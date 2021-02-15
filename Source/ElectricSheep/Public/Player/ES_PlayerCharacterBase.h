// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/ES_InteractInterface.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/BoxComponent.h"
#include "ES_PlayerCharacterBase.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;
class UWidgetInteractionComponent;

UCLASS(config = Game)
class ELECTRICSHEEP_API AES_PlayerCharacterBase : public ACharacter, public IES_InteractInterface
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FirstPersonCameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
    float Health;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
    FString Name;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
    FString Type;

public:
	// Sets default values for this character's properties
    AES_PlayerCharacterBase();

    /** First person camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
    UBoxComponent* InteractBoxCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    //UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Dialogue, meta = (AllowPrivateAccess = "true"))
    //UWidget* DialogueBox;

public:
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

    virtual void StartInteract_Implementation(ACharacter* character) override;

    virtual void EndInteract_Implementation() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
