// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeepDistanceManager.generated.h"

class AKeepDistanceActorBase;
UCLASS()
class PROGRAMMINGSKILLS_API AKeepDistanceManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeepDistanceManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<AActor*> KeepDistanceActors;

	/*
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<AKeepDistanceActorBase*, FVector> KeepDistanceActorMap;
	*/
};
