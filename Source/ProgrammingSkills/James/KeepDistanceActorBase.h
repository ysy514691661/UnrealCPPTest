// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeepDistanceManager.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "KeepDistanceActorBase.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API AKeepDistanceActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeepDistanceActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void KeepDistance();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUpdateDistance = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpeedToLerp = 20.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DistanceToKeep = 500.0f;

	UPROPERTY()
	APawn* PlayerPawn = nullptr;

	UPROPERTY()
	FVector TargetLocation;
	
	UPROPERTY()
	UArrowComponent* ArrowComponent = nullptr;

	UPROPERTY()
	AKeepDistanceManager* Manager;
	
};
