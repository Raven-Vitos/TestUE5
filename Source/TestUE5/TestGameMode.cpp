// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameMode.h"
#include "TestPlayerController.h"
#include "TestPlayer.h"

ATestGameMode::ATestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATestPlayerController::StaticClass();


}