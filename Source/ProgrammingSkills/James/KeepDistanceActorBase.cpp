// Fill out your copyright notice in the Description page of Project Settings.


#include "KeepDistanceActorBase.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AKeepDistanceActorBase::AKeepDistanceActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);
	ArrowComponent->SetVisibility(true);
	ArrowComponent->SetHiddenInGame(false);

}

// Called when the game starts or when spawned
void AKeepDistanceActorBase::BeginPlay()
{
	Super::BeginPlay();
	if (!PlayerPawn)
	{
		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	}
	if (!Manager)
	{
		Manager = Cast<AKeepDistanceManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AKeepDistanceManager::StaticClass()));
	}
}

// Called every frame
void AKeepDistanceActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	KeepDistance();
}

void AKeepDistanceActorBase::KeepDistance()
{
	if (!bUpdateDistance)
	{
		return;
	}
	if (!PlayerPawn)
	{
		return;
	}
	TargetLocation = PlayerPawn->GetActorLocation() +
		(PlayerPawn->GetActorRotation().Vector() * DistanceToKeep);
	if (Manager)
	{
		for (int i = 0; i < Manager->KeepDistanceActors.Num(); i++)
		{
			
			if (const AKeepDistanceActorBase* KeepDistanceActor = Cast<AKeepDistanceActorBase>(Manager->KeepDistanceActors[i]))
			{
				if ((KeepDistanceActor->TargetLocation == TargetLocation) && !(KeepDistanceActor == this))
				{
					FVector TransitVector =  i > 2 ? KeepDistanceActor->GetActorUpVector() : KeepDistanceActor->GetActorRightVector();
					TargetLocation = TargetLocation + (TransitVector * (100.0f * i));
				}
			}
		}
	}
	
	SetActorLocation(FMath::VInterpTo(GetActorLocation(), TargetLocation,
		GetWorld()->DeltaTimeSeconds, SpeedToLerp));
	
}

