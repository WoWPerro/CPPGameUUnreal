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

void AZombieFactoryCPP::HandlePlayerReload(AActor* player)
{
	SpawnZombie();
}

// Called every frame
void AZombieFactoryCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AZombieFactoryCPP::SpawnZombie()
{
	// Nos aseguramos de que el Blueprint fue asignado en el editor
	if (ZombieBlueprint)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Definimos dónde aparecerá el zombie (en este caso, donde está la factory)
			FVector Location = GetActorLocation();
			FRotator Rotation = GetActorRotation();

			// Usamos SpawnActor para crear una instancia del Blueprint
			World->SpawnActor<AEnemyBase>(ZombieBlueprint, Location, Rotation);

			UE_LOG(LogTemp, Warning, TEXT("Zombie Spawneado!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("¡ZombieBlueprint no asignado en el ZombieFactory!"));
	}
}

