// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "ShellActor.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	TankAiming 
	
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrel(UTankBarrel* Barrel)
{
	TankAimingComponent->SetTankBarrel(Barrel);
	LocalBarrel = Barrel;
}

void ATank::SetTurret(UTankTurret* Turret)
{
	TankAimingComponent->SetTankTurret(Turret);
}

void ATank::Fire()
{	
	if (!LocalBarrel) { return; }
	FTransform Location = LocalBarrel->GetSocketTransform(FName("Shoot"));
	GetWorld()->SpawnActor<AShellActor>(ShellBlueprint, Location)->LaunchProjectile(LocalBarrel->ShellSpeed);
}

void ATank::AimAt(FVector location)
{
	TankAimingComponent->RotateTurretTo(location);
}
