// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor_Daniel.h"

// Sets default values
ASpawnActor_Daniel::ASpawnActor_Daniel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnActor_Daniel::BeginPlay()
{
	Super::BeginPlay();
	spawnTest();
}

// Called every frame
void ASpawnActor_Daniel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnActor_Daniel::spawnTest()
{
	const FVector Location = GetActorLocation();
	const FRotator Rotation = GetActorRotation();
	if (!ActorToSpawn)
	{
		return;
	}
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation);
}
