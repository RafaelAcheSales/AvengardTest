// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/SuperJumpGameplayAbility.h"

USuperJumpGameplayAbility::USuperJumpGameplayAbility()
{
}

void USuperJumpGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ActivatedAbility"));
    // Usual ability activation checks
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        // Handle failure
        return;
    }

    ACustomCharacter* Character = Cast<ACustomCharacter>(ActorInfo->AvatarActor.Get());
    if (Character)
    {
        UCharacterMovementComponent* MovementComp = Character->GetCharacterMovement();
        if (MovementComp)
        {
            // Increase the jump force
            MovementComp->JumpZVelocity = 10000.0; // Set NewJumpForce to your desired value

            // Optionally, schedule a reset of the jump force after some time or under certain conditions
        }
    }
}

void USuperJumpGameplayAbility::ExecuteJump()
{
    //debug print
    UE_LOG(LogTemp, Warning, TEXT("Super Jump Activated"));
}
