// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere) //reflection 
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditDefaultsOnly, Category = stat) //reflection 
	int32 Hp;
	UPROPERTY(EditDefaultsOnly, Category = stat) //reflection 
	int32 Mp;

	UPROPERTY(EditDefaultsOnly, Category = stat) //reflection 
	float RotateSpeed = 30.f;
};
