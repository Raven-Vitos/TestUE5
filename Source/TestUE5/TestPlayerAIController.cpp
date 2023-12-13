// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerAIController.h"

ATestPlayerAIController::ATestPlayerAIController() : Super()
{
	// Добавьте отладочный вывод
	UE_LOG(LogTemp, Warning, TEXT("ATestPlayerAIController constructor called"));
}

void ATestPlayerAIController::SetPlayerTarget(APawn* PlayerPawn)
{
	if (PlayerPawn)
	{
		// Установите игрока как цель для врага
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn); // Ваш враг будет двигаться к игроку
	}
}

void ATestPlayerAIController::SetTargetLocation(const FVector& TargetLocation)
{
	// Устанавливаем координаты как цель для врага
	SetNewMoveDestination(TargetLocation);
}

void ATestPlayerAIController::SetNewMoveDestination(const FVector& Destination)
{
	// Если AI контроллер действителен
	if (GetPawn())
	{
		// Вызываем MoveTo для движения к новой цели
		MoveToLocation(Destination);
	}
}

void ATestPlayerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Вывести сообщение в лог
	UE_LOG(LogTemp, Warning, TEXT("ATestPlayerAIController Possess called"));

	// Добавить дополнительные проверки, если необходимо
	if (InPawn)
	{
		// Контроллер присоединен к персонажу
		UE_LOG(LogTemp, Warning, TEXT("AIController is possessing a pawn"));
	}
	else
	{
		// Контроллер не присоединен к персонажу
		UE_LOG(LogTemp, Warning, TEXT("MyController is nullptr"));
	}
}