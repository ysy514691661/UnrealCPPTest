// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnLooper();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::Spawn(FVector InVector, FRotator InRotation, FTransform& OutTransform)
{
	if (!ActorToSpawn)
	{
		return;
	}
	//@todo: make this a constant ref
	//FVector VecToUse = RootComponent->GetComponentLocation() + SumVector;

	SpawnedActors.Add(GetWorld()->SpawnActor<AActor>(ActorToSpawn, RandomPureVector(),
		UKismetMathLibrary::RandomRotator()));
	OutTransform =  FTransform(InRotation, InVector, FVector(1.0f, 1.0f, 1.0f));
}

FVector ASpawner::RandomPureVector()
{
	float x1 = FMath::FRandRange(RandomMin, RandomMax);
	float x2 = FMath::FRandRange(RandomMin, RandomMax);
	float x3 = FMath::FRandRange(RandomMin, RandomMax);

	/*
	FVector ReturnVector;
	RandomVectorizer(ReturnVector);
	return ReturnVector;
	*/
	return FVector(x1, x2, x3);
}

void ASpawner::SpawnIncrement()
{
	//if last spawn location equals to zero, set the last spawn location to root's world location
	if (LastSpawnLocation == FVector::ZeroVector)
	{
		LastSpawnLocation = RootComponent->GetComponentLocation();
	}

	n3 = n1 + n2;

	n1 = n2;

	n2 = n3;
	
	const float t1 = SpawnedActors.Num();
	//UE_LOG(LogTemp, Warning, TEXT("t1: %f"), t1)
	
	//add to variable SpawnedActors while also spawning an actor
	SpawnedActors.Add(GetWorld()->SpawnActor<AActor>(ActorToSpawn, LastSpawnLocation, FRotator::ZeroRotator));
	
	const float t2 = SpawnedActors.Num();
	//UE_LOG(LogTemp, Warning, TEXT("t2: %f"), t2)

	
	fChangeVector = t1 + t2;

	//float SpawnY = (fChangeVector += SpawnedNumbers);
	//float SpawnZ = (fChangeVector += SpawnedNumbers);
	
	LastSpawnLocation = FVector((n1-1)/1.618f, (1-(n1-1))/1.618, 0.0);
	
	//UE_LOG(LogTemp, Warning, TEXT("tR: %f"), fChangeVector)
	//UE_LOG(LogTemp, Warning, TEXT(" "))

	UE_LOG(LogTemp, Warning, TEXT("Spawned Actor Class at %s"), *LastSpawnLocation.ToString())
	//UE_LOG(LogTemp, Warning, TEXT("n2: %f"), n2)
	//UE_LOG(LogTemp, Warning, TEXT("n3: %f"), n3)
}

FVector ASpawner::RandomVector()
{
	float x = FMath::FRandRange(RandomMin, RandomMax);
	float y = FMath::FRandRange(RandomMin, RandomMax);
	float z = FMath::FRandRange(RandomMin, RandomMax);
	return FVector(x,y,z);
}

FVector ASpawner::GetRootWorldLocation()
{
	return RootComponent->GetComponentLocation();
}

void ASpawner::SpawnLooper()
{
	GetWorld()->GetTimerManager().SetTimer(InputTimerHandle, this, &ASpawner::SpawnIncrement, SpawnRate, true);
}

void ASpawner::TestSpawn()
{
	FTransform OutTransform;
	Spawn(RandomPureVector(), UKismetMathLibrary::RandomRotator(true), OutTransform );
	const FVector OutVector = OutTransform.GetTranslation();
	UE_LOG(LogTemp, Warning, TEXT("Spawned Actor Class at %s"), *OutVector.ToString())
	if (false)
	{
		InputTimerHandle.Invalidate();
	}
}

void ASpawner::SpawnFib()
{
	if (LastSpawnLocation == FVector::ZeroVector)
	{
		LastSpawnLocation = RootComponent->GetComponentLocation();
	}
	//SpawnedActors.Add(GetWorld()->SpawnActor<AActor>(ActorToSpawn, LastSpawnLocation, FRotator::ZeroRotator));
	fNextTerm = fPreviousTerm + fCurrentTerm;
	fCurrentTerm = fPreviousTerm;
	fPreviousTerm = fNextTerm;

	UE_LOG(LogTemp, Warning, TEXT("Output: %f"), fCurrentTerm)
	
}
