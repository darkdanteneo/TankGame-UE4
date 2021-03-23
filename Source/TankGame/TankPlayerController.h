// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "Engine\World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltTime) override;
private:
	ATank* GetControlledTank() const;
	void AimTowardsCross();
	bool GetRayHitlocation(FVector& OutHitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXlocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYlocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};