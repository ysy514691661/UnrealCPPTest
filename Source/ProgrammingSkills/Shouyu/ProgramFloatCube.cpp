// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgramFloatCube.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AProgramFloatCube::AProgramFloatCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ShownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestMesh"));
	ShownMesh ->SetupAttachment(RootComponent);
	LocationAddAmount = 0;

}

void AProgramFloatCube::FloatAndRotate()
{
	
	FVector desLocation = GetActorLocation();
	FRotator desRoatation = GetActorRotation();
	LocationAddAmount += FApp::GetDeltaTime();
	
	desLocation.Z += UKismetMathLibrary::Sin(LocationAddAmount);
	// FString TheFloatStr = FString::SanitizeFloat(desLocation.Z);
	// GEngine->AddOnScreenDebugMessage( -1,1.0,FColor::Red, *TheFloatStr );

	SetActorLocation(desLocation);
	desRoatation.Yaw += 1.0f;
	

	SetActorRotation(desRoatation);

	
}

// Called when the game starts or when spawned
void AProgramFloatCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProgramFloatCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FloatAndRotate();
}

