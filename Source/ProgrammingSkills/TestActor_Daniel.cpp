// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor_Daniel.h"

#include "Engine/Engine.h"

// Sets default values
ATestActor_Daniel::ATestActor_Daniel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UStaticMeshComponent>("BoxComponent");
	Box->SetStaticMesh(CubeMesh);
	Box->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ATestActor_Daniel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor_Daniel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor_Daniel::goodMorning()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi"));
	GEngine->AddOnScreenDebugMessage(-1, DisplayTime, MessageColor, DebugMessageUnique);
	return;
}

void ATestActor_Daniel::goodNight()
{
	DisplayTime = 15.0f;
	MessageColor = FColor::Purple;
	DebugMessageUnique = TEXT("Goodnight my sweet prince");
	GEngine->AddOnScreenDebugMessage(-1, DisplayTime, MessageColor, DebugMessageUnique);
	return;
}

void ATestActor_Daniel::spawnCube()
{
}