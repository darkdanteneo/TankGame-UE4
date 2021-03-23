// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float Elevation)
{
		Elevation = FMath::Clamp(Elevation, -1.f, 1.f);
		float ElevationTarget = GetRelativeRotation().Pitch + (Elevation * MaxMovementSpeed * GetWorld()->DeltaTimeSeconds);
		ElevationTarget = FMath::Clamp(ElevationTarget, 0.f, 20.f);

		//UE_LOG(LogTemp, Warning, TEXT("%f"), ElevationTarget);
		SetRelativeRotation(FRotator(ElevationTarget, 0, 0));
}
