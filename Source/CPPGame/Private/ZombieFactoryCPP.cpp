// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieFactoryCPP.h"
#include "CPPGame/CPPGameCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AZombieFactoryCPP::AZombieFactoryCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombieFactoryCPP::BeginPlay()
{
	Super::BeginPlay();
	ACharacter* ACharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	ACPPGameCharacter* AcppGameCharacter = Cast<ACPPGameCharacter>(ACharacter);

	if(AcppGameCharacter)
	{
		AcppGameCharacter->OnReload.AddDynamic(this, &AZombieFactoryCPP::HandlePlayerReload);
	}
}

void AZombieFactoryCPP::HandlePlayerReload()
{
	SpawnZombie();
}

// Called every frame
void AZombieFactoryCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

