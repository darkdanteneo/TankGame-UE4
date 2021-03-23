// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "AITankController.generated.h"

UCLASS()
class TANKGAME_API AAITankController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	float LastFire = 0;
	ATank* PlayerTank = nullptr;
	ATank* Aitank = nullptr;
public:
	UPROPERTY(EditAnywhere)
	float ReloadTime = 5;
};
