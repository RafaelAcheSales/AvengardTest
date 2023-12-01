// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Characters/CustomCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SuperJumpGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class AVENGARDTEST_API USuperJumpGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
    // Constructor
    USuperJumpGameplayAbility();

protected:
    // The activation function for the ability
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;

    // Handle the jump logic
    void ExecuteJump();

    // Optionally, override other functions as needed, for example:
    // - CommitAbility() for handling resource consumption
    // - EndAbility() for cleanup when the ability ends
    // - You can also add functions for cooldown management, effects, etc.

private:
    // Add private member variables here if needed, like jump height, cooldown time, etc.
};