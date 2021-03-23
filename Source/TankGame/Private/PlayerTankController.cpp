// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTankController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void APlayerTankController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetPlayerTank()->GetName());
}


void APlayerTankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CrossHairLocation;
	GetCrosshairLocation(CrossHairLocation);
	GetPlayerTank()->AimAt(CrossHairLocation);
}

ATank* APlayerTankController::GetPlayerTank() const
{
	return Cast<ATank>(GetPawn());
}

void APlayerTankController::GetCrosshairLocation(FVector& HitLocation)
{
	int32 LocationX, LocationY;
	FVector WorldLocation, WorldDirection;
	FHitResult Hit;
	GetViewportSize(LocationX, LocationY);
	LocationX = LocationX * OffsetX;
	LocationY = LocationY * OffsetY;
	DeprojectScreenPositionToWorld(LocationX, LocationY, WorldDirection, WorldLocation);

	FVector StartTrace = PlayerCameraManager->GetCameraLocation();
	FVector EndTrace = StartTrace + (WorldLocation * ShellRange);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility);
	HitLocation = Hit.Location;
}




