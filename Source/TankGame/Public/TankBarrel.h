// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float Elevation);
	UPROPERTY(EditAnywhere)
	float ShellSpeed = 150000;
	UPROPERTY(EditAnywhere)
	float MaxMovementSpeed = 25;
private:
};
