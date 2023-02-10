// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor_Daniel.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API ASpawnActor_Daniel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnActor_Daniel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawn Things")
	void spawnTest();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Empty")
	TSubclassOf<AActor> ActorToSpawn;
	
};
