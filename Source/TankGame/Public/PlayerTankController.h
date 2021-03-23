// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "PlayerTankController.generated.h"


UCLASS()
class TANKGAME_API APlayerTankController : public APlayerController
{
	GENERATED_BODY()
private:
	float OffsetX = 0.5;
	float OffsetY = 0.35;
	float ShellRange = 1000000;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	ATank* GetPlayerTank() const;
	void GetCrosshairLocation(FVector& HitLocation);
	
};
