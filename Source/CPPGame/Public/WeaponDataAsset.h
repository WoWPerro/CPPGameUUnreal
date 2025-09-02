// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CPPGAME_API UWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
	float Damage = 25.0f;

	UPROPERTY(EditAnywhere, Category = "Weapon Stats")
	int32 MaxAmmo = 12;
};
