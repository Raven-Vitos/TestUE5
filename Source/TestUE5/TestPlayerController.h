// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTUE5_API ATestPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void BeginPlay() override;

	uint32 bMoveToMouseCursor : 1;

	virtual void PlayerTick(float DeltaTime) override;

	void MoveForward(float Value);
	void MoveRight(float Value);


public:
	ATestPlayerController();

	virtual void SetupInputComponent() override;

};
