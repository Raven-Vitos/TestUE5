// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TestPlayerAIController.generated.h"

/**
 * 
 */
UCLASS()
class TESTUE5_API ATestPlayerAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATestPlayerAIController();

	void OnPossess(APawn* InPawn) override;

	// Функция для установки игрока как цели для врага
	void SetPlayerTarget(APawn* PlayerPawn);

	void SetTargetLocation(const FVector& TargetLocation);

	void SetNewMoveDestination(const FVector& Destination);
};
