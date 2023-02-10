// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProgramPointToActor.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API AProgramPointToActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AProgramPointToActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* ActorToPoint;

	UFUNCTION(BlueprintCallable)
	void PointAndScale();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
};
