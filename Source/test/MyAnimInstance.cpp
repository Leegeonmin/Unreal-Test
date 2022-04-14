// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
UMyAnimInstance::UMyAnimInstance() 
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Minion_Lane_Core_Skeleton_Montage.Minion_Lane_Core_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}
void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(AttackMontage))
	{
		Montage_Play(AttackMontage, 1.f);
	}
}
void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
			//attackmouse = Character->GetMovementComponent()->
		}
	}
}
