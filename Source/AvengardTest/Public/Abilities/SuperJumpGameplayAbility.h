// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Effects/PlayerGameplayEffect.h"
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

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
    TSubclassOf<UGameplayEffect> SuperJumpEffectClass;



protected:


private:
    // Add private member variables here if needed, like jump height, cooldown time, etc.
};