// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Delegates/Delegate.h"
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributeSetBase.generated.h"
// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class AVENGARDTEST_API UPlayerAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UPlayerAttributeSetBase();
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSetBase, Mana)

	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSetBase, MaxMana)

	UPROPERTY(BlueprintReadOnly, Category = "JumpForce", ReplicatedUsing = OnRep_JumpForce)
	FGameplayAttributeData JumpForce;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSetBase, JumpForce)

	UPROPERTY(BlueprintReadOnly, Category = "JumpForce", ReplicatedUsing = OnRep_MaxJumpForce)
	FGameplayAttributeData MaxJumpForce;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSetBase, MaxJumpForce)

	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	virtual void OnRep_JumpForce(const FGameplayAttributeData& OldJumpForce);
	UFUNCTION()
	virtual void OnRep_MaxJumpForce(const FGameplayAttributeData& OldMaxJumpForce);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Delegate definition
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChangedDelegate, float, Mana, float, MaxMana);
	FOnManaChangedDelegate OnManaChangedDelegate;

};
