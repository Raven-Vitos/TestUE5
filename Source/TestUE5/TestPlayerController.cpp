// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerController.h"
#include <Kismet/GameplayStatics.h>
#include <Camera/CameraActor.h>

ATestPlayerController::ATestPlayerController()
{
	bShowMouseCursor = true;
}

void ATestPlayerController::BeginPlay()
{
	Super::BeginPlay();

}


void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Привязка функций к клавишам
	InputComponent->BindAxis("MoveForward", this, &ATestPlayerController::MoveForward);
	InputComponent->BindAxis("MoveBackward", this, &ATestPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATestPlayerController::MoveRight);
	InputComponent->BindAxis("MoveLeft", this, &ATestPlayerController::MoveRight);
}

void ATestPlayerController::MoveForward(float Value)
{
	// Логика движения вперед
	FVector Direction = FVector::ForwardVector;
	GetPawn()->AddMovementInput(Direction, Value);
}

void ATestPlayerController::MoveRight(float Value)
{
	// Логика движения вправо
	FVector Direction = FVector::RightVector;
	GetPawn()->AddMovementInput(Direction, Value);
}

void ATestPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		//MoveToMouseCursor();
	}
}