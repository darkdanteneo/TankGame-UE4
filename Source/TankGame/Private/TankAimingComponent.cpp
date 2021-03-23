// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetTankBarrel(UTankBarrel* barrel)
{
	Barrel = barrel;
}

void UTankAimingComponent::SetTankTurret(UTankTurret* turret)
{
	Turret = turret;
}

void UTankAimingComponent::RotateTurretTo(FVector WorldLocation)
{
	FRotator Rotate = CalculateRequiredRotation(WorldLocation) - FRotator(Barrel->GetForwardVector().Rotation().Pitch, Turret->GetForwardVector().Rotation().Yaw, 0);
	Barrel->Elevate(Rotate.Pitch);
	Turret->Rotate(Rotate.Yaw);
}

FRotator UTankAimingComponent::CalculateRequiredRotation(FVector WorldLocation)
{
	FVector ProjectileVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Shoot"));
	/*
	bool SolutionExist = UGameplayStatics::SuggestProjectileVelocity(this,
		ProjectileVelocity,
		StartLocation,
		WorldLocation,
		Barrel->ShellSpeed,
		false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (SolutionExist) { return ProjectileVelocity.GetSafeNormal().Rotation(); }
	return FRotator(0, 0, 0);
	*/
	return UKismetMathLibrary::FindLookAtRotation(StartLocation, WorldLocation);
}
