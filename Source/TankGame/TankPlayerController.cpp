// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Log, TEXT("The player tank is %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank is not possed"));
	}
}

void ATankPlayerController::Tick(float DeltTime)
{
	Super::Tick(DeltTime);
	AimTowardsCross();
}


void ATankPlayerController::AimTowardsCross()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if(GetRayHitlocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetRayHitlocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX,ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = {ViewportSizeX * 0.55f, ViewportSizeY * 0.333333f};
	FVector LookDirection, WorldLocation;
	if(DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection ))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto Startlocation  = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = Startlocation + (LookDirection * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel
			(HitResult, 
			Startlocation, 
			EndLocation, 
			ECollisionChannel::ECC_Visibility))
			{
				OutHitLocation = HitResult.Location;
				return true;
			}
	OutHitLocation = FVector(0);
	return false;
}