// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>
#include "UObject/UObjectGlobals.h"
#include "GameFramework/Controller.h"


// Sets default values
ATestPlayer::ATestPlayer()
{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	UCharacterMovementComponent* CharacterMovementComponen = GetCharacterMovement();
	CharacterMovementComponen->bOrientRotationToMovement = true; // Rotate character to moving direction
	CharacterMovementComponen->RotationRate = FRotator(0.f, 640.f, 0.f);
	CharacterMovementComponen->bConstrainToPlane = true;
	CharacterMovementComponen->bSnapToPlaneAtStart = true;

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	if (SpringArm)
	{
		SpringArm->SetupAttachment(RootComponent);
		SpringArm->TargetArmLength = 1000.0f; // Adjust the arm length as needed
		SpringArm->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
		SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
		SpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	}

	// Create a camera component
	CameraPlayer = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (CameraPlayer)
	{
		CameraPlayer->SetupAttachment(SpringArm);
		CameraPlayer->bUsePawnControlRotation = false;
	}



	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ATestPlayer::BeginPlay()
{
	Super::BeginPlay();

	BaseCharacter = GetWorld()->SpawnActor<ATestCharacter>(ATestCharacter::StaticClass(), GetActorLocation(), FRotator::ZeroRotator);

	if (BaseCharacter)
	{
		// Получаем контроллер персонажа
		AController* NewController = BaseCharacter->GetController();

		if (NewController)
		{
			// Устанавливаем AIController для персонажа
			AAIController* NewAIController = Cast<AAIController>(NewController);
			if (NewAIController)
			{
				// Possess AIController
				NewAIController->Possess(BaseCharacter);
			}
		}
	}
}

// Called every frame
void ATestPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
