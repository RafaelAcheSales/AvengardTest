// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/AttributeSets/PlayerAttributeSetBase.h"
#include "Net/UnrealNetwork.h"

void UPlayerAttributeSetBase::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSetBase, Mana, OldMana);
}

void UPlayerAttributeSetBase::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSetBase, MaxMana, OldMaxMana);
}

void UPlayerAttributeSetBase::OnRep_JumpForce(const FGameplayAttributeData& OldJumpForce)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSetBase, JumpForce, OldJumpForce);
}

void UPlayerAttributeSetBase::OnRep_MaxJumpForce(const FGameplayAttributeData& OldMaxJumpForce)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSetBase, MaxJumpForce, OldMaxJumpForce);
}

void UPlayerAttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxMana());
	}
	else if (Attribute == GetJumpForceAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxJumpForce());
	}

}

void UPlayerAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPlayerAttributeSetBase, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPlayerAttributeSetBase, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPlayerAttributeSetBase, JumpForce, COND_None, REPNOTIFY_Always);
}
