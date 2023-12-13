// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerAIController.h"

ATestPlayerAIController::ATestPlayerAIController() : Super()
{
	// �������� ���������� �����
	UE_LOG(LogTemp, Warning, TEXT("ATestPlayerAIController constructor called"));
}

void ATestPlayerAIController::SetPlayerTarget(APawn* PlayerPawn)
{
	if (PlayerPawn)
	{
		// ���������� ������ ��� ���� ��� �����
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn); // ��� ���� ����� ��������� � ������
	}
}

void ATestPlayerAIController::SetTargetLocation(const FVector& TargetLocation)
{
	// ������������� ���������� ��� ���� ��� �����
	SetNewMoveDestination(TargetLocation);
}

void ATestPlayerAIController::SetNewMoveDestination(const FVector& Destination)
{
	// ���� AI ���������� ������������
	if (GetPawn())
	{
		// �������� MoveTo ��� �������� � ����� ����
		MoveToLocation(Destination);
	}
}

void ATestPlayerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// ������� ��������� � ���
	UE_LOG(LogTemp, Warning, TEXT("ATestPlayerAIController Possess called"));

	// �������� �������������� ��������, ���� ����������
	if (InPawn)
	{
		// ���������� ����������� � ���������
		UE_LOG(LogTemp, Warning, TEXT("AIController is possessing a pawn"));
	}
	else
	{
		// ���������� �� ����������� � ���������
		UE_LOG(LogTemp, Warning, TEXT("MyController is nullptr"));
	}
}