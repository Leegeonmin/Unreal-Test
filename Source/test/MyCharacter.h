// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override
	{
		Super::SetupPlayerInputComponent(PlayerInputComponent);

		PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
		PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
		PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
		PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
		PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);

	}

	void UpDown(float Value);
	void LeftRight(float Value);
	void Yaw(float Value);
	void Attack();
	void Jump();

private :
	UPROPERTY(VisibleAnywhere) //reflection 
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere) //reflection 
	class UCameraComponent* Camera;
};
