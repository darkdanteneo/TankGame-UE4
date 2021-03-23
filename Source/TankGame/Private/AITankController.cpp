// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "Tank.h"
#include "Engine/World.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Aitank = Cast<ATank>(GetPawn());
}

void AAITankController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Aitank->AimAt(PlayerTank->GetActorLocation());
	if (GetWorld()->GetTimeSeconds() - LastFire >= ReloadTime)
	{
		LastFire = GetWorld()->GetTimeSeconds();
		Aitank->Fire();
	}
}
