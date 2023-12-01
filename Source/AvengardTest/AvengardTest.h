// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum class EAbilityInput : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Confirm = 1 UMETA(DisplayName = "Confirm"),
	Cancel = 2 UMETA(DisplayName = "Cancel"),
	SuperJump = 3 UMETA(DisplayName = "SuperJump"),
};