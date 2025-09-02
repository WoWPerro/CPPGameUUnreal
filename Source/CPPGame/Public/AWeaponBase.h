// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include  "WeaponDataAsset.h"
#include "AWeaponBase.generated.h"

UCLASS()
class CPPGAME_API AAWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AAWeaponBase();
	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
	void OnFireFX();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Config")
	UWeaponDataAsset* WeaponData;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	int32 CurrentAmmo;

public:	
	virtual void Tick(float DeltaTime) override;
};
