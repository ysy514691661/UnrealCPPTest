// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FibSpawnHandler.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API AFibSpawnHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFibSpawnHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TArray<AActor*> FibSpawnedActors;

	UFUNCTION()
	void SpawnFib();

	UFUNCTION()
	void SpawnLoop();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FibSpawnRate = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> ClassToSpawn;
	
	UPROPERTY()
	FVector LastSpawnLocation;
};
