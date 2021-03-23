// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankTurret;
class UTankBarrel;
class AShellActor;
UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AShellActor> ShellBlueprint;

	UTankBarrel* LocalBarrel = nullptr;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetBarrel(UTankBarrel* Barrel);
	UFUNCTION(BlueprintCallable)
	void SetTurret(UTankTurret* Turret);
	UFUNCTION(BlueprintCallable)
	void Fire();
	void AimAt(FVector);
	
	UTankAimingComponent* TankAimingComponent = nullptr;
};
