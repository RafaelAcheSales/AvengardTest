#include "Abilities/Components/PlayerAbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemGlobals.h"
#include "Abilities/GameplayAbility.h"

bool UPlayerAbilitySystemComponent::GetCooldownRemainingForAbility(TSubclassOf<UGameplayAbility> AbilityClass, float& TimeRemaining, float& CooldownDuration) const
{
    TimeRemaining = 0.0f;
    CooldownDuration = 0.0f;

    if (!AbilityClass)
    {
        return false;
    }

    const UGameplayAbility* Ability = AbilityClass.GetDefaultObject();
    FGameplayTagContainer CooldownTags = *Ability->GetCooldownTags();
    

    if (CooldownTags.IsEmpty())
    {
        return false;
    }

    FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyEffectTags(CooldownTags);
    TArray<TPair<float, float>> Durations = GetActiveEffectsTimeRemainingAndDuration(Query);
    if (Durations.Num() > 0)
    {
        TimeRemaining = Durations[0].Key;
        CooldownDuration = Durations[0].Value;
        return true;
    }

    return false;
}


bool UPlayerAbilitySystemComponent::GetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration) const
{
    TimeRemaining = 0.0f;
    CooldownDuration = 0.0f;

    if (CooldownTags.IsEmpty())
    {
        return false;
    }

    const FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyEffectTags(CooldownTags);
    TArray<TPair<float, float>> Durations = GetActiveEffectsTimeRemainingAndDuration(Query);
    if (Durations.Num() > 0)
    {
        int32 BestIdx = 0;
        float LongestTime = -1.0f;

        for (int32 Idx = 0; Idx < Durations.Num(); ++Idx)
        {
            TPair<float, float> Pair = Durations[Idx];
            if (Pair.Key > LongestTime)
            {
                LongestTime = Pair.Key;
                BestIdx = Idx;
            }
        }

        TimeRemaining = Durations[BestIdx].Key;
        CooldownDuration = Durations[BestIdx].Value;

        return true;
    }

    return false;
}
