// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CustomCharacter.h"
#include "AbilitySystemGlobals.h"
#include "Engine/Engine.h"

// Sets default values
ACustomCharacter::ACustomCharacter(const class FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// Create custom ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<UPlayerAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Create the attributes set
	AttributeSet = CreateDefaultSubobject<UPlayerAttributeSetBase>(TEXT("AttributeSet"));

}

void ACustomCharacter::SetMana(float ManaValue)
{
	if (AttributeSet)
	{
		AttributeSet->SetMana(ManaValue);
	}
}

void ACustomCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeAbilities();
	//Debug if its being called
	// Create a debug message
	
	if (AbilitySystemComponent)
	{
		// Bind to attribute change using the Ability System Component
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSetBase::GetJumpForceAttribute()).AddUObject(this, &ACustomCharacter::OnJumpForceChanged);
	}
}

void ACustomCharacter::OnJumpForceChanged(const FOnAttributeChangeData& Data)
{

}

// Called every frame
void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACustomCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ACustomCharacter::InitializeAbilities()
{
	if (IsValid(AbilitySystemComponent))
	{
		FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(
			FGameplayAbilitySpec(USuperJumpGameplayAbility::StaticClass(), 1, INDEX_NONE, this));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Initialize"));

	}
}

void ACustomCharacter::Jump()
{
	Super::Jump();
}

float ACustomCharacter::GetMana() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetMana();
	}
	return 0.0f;
}

float ACustomCharacter::GetMaxMana() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetMaxMana();
	}
	return 0.0f;
}

void ACustomCharacter::ActivateAbility(int32 InputID)
{
	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->AbilityLocalInputPressed(InputID);

		AbilitySystemComponent->TryActivateAbilityByClass(JumpAbility);
	}
}

