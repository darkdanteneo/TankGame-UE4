// Fill out your copyright notice in the Description page of Project Settings.


#include "ShellActor.h"

// Sets default values
AShellActor::AShellActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ShellMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Shell Movement"));
	ShellMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AShellActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShellActor::LaunchProjectile(float speed)
{
	ShellMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ShellMovement->Activate();
}

