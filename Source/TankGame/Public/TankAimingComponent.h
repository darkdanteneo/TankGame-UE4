// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();
	void SetTankBarrel(UTankBarrel* barrel);
	void SetTankTurret(UTankTurret* turret);
	void RotateTurretTo(FVector);
	FRotator CalculateRequiredRotation(FVector);
private:
	UTankBarrel* Barrel;
	UTankTurret* Turret;
};
