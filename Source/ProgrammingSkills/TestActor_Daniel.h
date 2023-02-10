// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnActor_Daniel.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "TestActor_Daniel.generated.h"

UCLASS()
class PROGRAMMINGSKILLS_API ATestActor_Daniel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor_Daniel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** This prints Good Morning */
	UFUNCTION(BlueprintCallable, Category = "Greetings | Good Morning")
	void goodMorning();

	UFUNCTION(BlueprintCallable, Category = "Greetings | Good Night")
	void goodNight();

	UFUNCTION(BlueprintCallable, Category = "Spawn Stuff | Spawn Cube")
	void spawnCube();
	
	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//ASpawnActor_Daniel* MyTestSpawnActor = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug Params | Strings")
	FString DebugMessageUnique = TEXT("DefaultDebugMessageUnique");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug Params | Floats")
	float DisplayTime = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug Params | Colors")
	FColor MessageColor = FColor(1,1,1,1);
	//FColor MessageColor = FColor::Orange;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawn Mesh | Box")
	UStaticMeshComponent* Box = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawn Mesh | Box")
	UStaticMesh* CubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
};
