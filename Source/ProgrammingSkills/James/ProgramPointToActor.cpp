// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgramPointToActor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AProgramPointToActor::AProgramPointToActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AProgramPointToActor::PointAndScale()
{
	FVector LocationTo;
	FRotator RotationTo;

	//point
	if (ActorToPoint)
	{
		LocationTo = ActorToPoint->GetActorLocation();
	}
	else
	{
		LocationTo = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
	}
	RotationTo = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), LocationTo);
	FRotator SmoothRotationTo;
	SmoothRotationTo = UKismetMathLibrary::RInterpTo(GetActorRotation(), RotationTo,
		UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 1.0f);
	SetActorRotation(SmoothRotationTo);

	//scale
	FVector ScaleToSet;
	float UnVectoredFloat;
	float DistanceScaled;
	DistanceScaled = UKismetMathLibrary::VSize((GetActorLocation() - LocationTo)) / 100.0f;
	UnVectoredFloat = UKismetMathLibrary::FInterpTo(GetActorScale().X, DistanceScaled,
		UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 1.0f );

	ScaleToSet = FVector(UnVectoredFloat, UnVectoredFloat, UnVectoredFloat);
	SetActorScale3D(ScaleToSet);
}

// Called when the game starts or when spawned
void AProgramPointToActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProgramPointToActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

