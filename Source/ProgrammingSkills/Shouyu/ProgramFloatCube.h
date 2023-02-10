// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProgramFloatCube.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API AProgramFloatCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProgramFloatCube();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ShownMesh;

	float LocationAddAmount;

	UFUNCTION(BlueprintCallable)
	void FloatAndRotate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
