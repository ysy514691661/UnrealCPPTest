// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Spawn(FVector InVector, FRotator InRotation, FTransform& OutTransform);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	//Get A Random Vector using Blueprint Pure, Daniel Rocks
	//UFUNCTION(BlueprintCallable, BlueprintPure)
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector RandomPureVector();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector RandomVector();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetRootWorldLocation();

	UFUNCTION(BlueprintCallable)
	void SpawnLooper();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpawnRate = 1.0;

	UFUNCTION(BlueprintCallable)
	void SpawnIncrement();
	
	UFUNCTION()
	void TestSpawn();

	UPROPERTY()
	TArray<AActor*> SpawnedActors;
	
	FTimerHandle InputTimerHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float fChangeVector = 1.0f; 
	
	float RandomMin = -100.0f;
	float RandomMax = 100.0f;

	UFUNCTION()
	void SpawnFib();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float fCurrentTerm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float fPreviousTerm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float fNextTerm;
	
	FVector LastSpawnLocation;
	
	int n1 = 0, n2 = 1, n3;
};
