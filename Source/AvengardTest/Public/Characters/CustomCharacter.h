// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Abilities/Components/PlayerAbilitySystemComponent.h"
#include "Abilities/AttributeSets/PlayerAttributeSetBase.h"
#include "AbilitySystemInterface.h"
#include "CustomCharacter.generated.h"

UCLASS()
class AVENGARDTEST_API ACustomCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACustomCharacter(const class FObjectInitializer& ObjectInitializer);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Sets default values for this character's properties

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Initialize our abilities
	virtual void InitializeAbilities();

	// Override the native jump function to use our custom JumpForce attribute
	virtual void Jump() override;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	float GetMana() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ActivateAbility(int32 InputID);

protected:
	FGameplayTag SuperJumpTag;

	// Ability system component (base class pointer)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;

	// Attributes set
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UPlayerAttributeSetBase* AttributeSet;

	// Jump ability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSubclassOf<UGameplayAbility> JumpAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	virtual void  SetMana(float ManaValue);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Handle attribute changes
	void OnJumpForceChanged(const FOnAttributeChangeData& Data);
};
