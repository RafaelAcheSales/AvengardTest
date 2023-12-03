// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/SuperJumpGameplayAbility.h"

USuperJumpGameplayAbility::USuperJumpGameplayAbility()
{
}


    


void USuperJumpGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{

    
    // Usual ability activation checks
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        // Handle failure
        return;
    }
    UAbilitySystemComponent* AbilitySystemComponent = GetAbilitySystemComponentFromActorInfo();


    

}

void USuperJumpGameplayAbility::ExecuteJump()
{
    //debug print
    UE_LOG(LogTemp, Warning, TEXT("Super Jump Activated"));
}
