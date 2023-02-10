// Fill out your copyright notice in the Description page of Project Settings.


#include "KeepDistanceManager.h"

#include "KeepDistanceActorBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKeepDistanceManager::AKeepDistanceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKeepDistanceManager::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> OutArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AKeepDistanceActorBase::StaticClass(), OutArray);
	KeepDistanceActors = OutArray;
	/*
	for (const auto InActor : OutArray)
	{
		AKeepDistanceActorBase* LocalActor = Cast<AKeepDistanceActorBase>(InActor);
		KeepDistanceActorMap.Add(LocalActor, LocalActor->GetActorLocation());
	}
	*/
}

// Called every frame
void AKeepDistanceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	for (auto Input : KeepDistanceActors)
	{
		AKeepDistanceActorBase* LocalActor = Cast<AKeepDistanceActorBase>(Input);
		KeepDistanceActorMap.Emplace(LocalActor, Input->GetActorLocation());
	}
	*/

}

