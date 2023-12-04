// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Abilities/SuperJumpGameplayAbility.h"
#include "PlayerAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class AVENGARDTEST_API UPlayerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "AbilitySystemComponent")
	virtual bool GetCooldownRemainingForAbility(TSubclassOf<UGameplayAbility> AbilityClass, float& TimeRemaining, float& CooldownDuration) const;

	UFUNCTION(BlueprintCallable, Category = "AbilitySystemComponent")
	virtual bool GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration) const;




};
