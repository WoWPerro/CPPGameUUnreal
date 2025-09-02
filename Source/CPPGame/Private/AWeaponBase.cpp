// Fill out your copyright notice in the Description page of Project Settings.


#include "AWeaponBase.h"

// Sets default values
AAWeaponBase::AAWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponData)
	{
		CurrentAmmo = WeaponData->MaxAmmo;
	}
	
}

// Called every frame
void AAWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAWeaponBase::Fire()
{
	// REGLA 1: ¿Tengo un Data Asset?
	if (!WeaponData) return;

	// REGLA 2: ¿Tengo munición?
	if (CurrentAmmo > 0)
	{
		CurrentAmmo--;
		UE_LOG(LogTemp, Warning, TEXT("¡BANG! Daño: %f, Munición restante: %d"), WeaponData->Damage, CurrentAmmo);

		// EVENTO CLAVE: Anunciamos que ocurrió un disparo exitoso.
		OnFireFX();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("¡CLICK! Sin munición."));
	}
}
