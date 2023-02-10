// Fill out your copyright notice in the Description page of Project Settings.


#include "FibSpawnHandler.h"

// Sets default values
AFibSpawnHandler::AFibSpawnHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFibSpawnHandler::BeginPlay()
{
	Super::BeginPlay();
	SpawnLoop();
	
}

// Called every frame
void AFibSpawnHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFibSpawnHandler::SpawnFib()
{
	
	if (LastSpawnLocation == FVector::ZeroVector)
	{
		LastSpawnLocation = RootComponent->GetComponentLocation();
		if (LastSpawnLocation == FVector::ZeroVector)
		{
			LastSpawnLocation = LastSpawnLocation + FVector(1.0f, 0.0f, 0.0f);
		}
	}
	
	const uint64 FibSize = FibSpawnedActors.Num();
	
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ClassToSpawn, LastSpawnLocation, FRotator::ZeroRotator);
	FibSpawnedActors.Add(SpawnedActor);
	if (FibSize && FibSpawnedActors[FibSize - 1])
	{
		LastSpawnLocation = LastSpawnLocation + FibSpawnedActors[FibSize - 1]->GetActorLocation();
	}
}

void AFibSpawnHandler::SpawnLoop()
{
	FTimerHandle BlankTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(BlankTimerHandle, this, &AFibSpawnHandler::SpawnFib, FibSpawnRate, true);
}

