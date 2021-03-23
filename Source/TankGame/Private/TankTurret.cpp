// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float Yaw)
{
		if (Yaw > 180.f || Yaw < -180.f) { Yaw = -Yaw; }
		Yaw = FMath::Clamp(Yaw, -1.f, 1.f);
		float YawTarget = GetRelativeRotation().Yaw + (Yaw * MovementSpeed * GetWorld()->DeltaTimeSeconds);
		SetRelativeRotation(FRotator(0, YawTarget, 0));
		
}
