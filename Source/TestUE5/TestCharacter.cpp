// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/MovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������������� �������� ��������� (������ ��� �������)
	//RootComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));

	// Set size for player capsule
	UCapsuleComponent* capsuleComponent = GetCapsuleComponent();
	capsuleComponent->InitCapsuleSize(42.f, 96.0f);
	capsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//capsuleComponent->SetSimulatePhysics(true);
	capsuleComponent->SetEnableGravity(true);
	capsuleComponent->SetCollisionProfileName(TEXT("Pawn"));

	// �������� �������������� ������� (SixDOF) � �������������
	UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(capsuleComponent);

	FBodyInstance* BodyInstance = Primitive->GetBodyInstance();

	BodyInstance->bLockXRotation = true;
	BodyInstance->bLockYRotation = true;
	BodyInstance->bLockZRotation = true;

	// ��������� ����������� ��������� �����
	UStaticMeshComponent* SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMeshComponent->SetupAttachment(RootComponent);  // ������������ � ��������� ����������

	// ��������� ����������� ����� �� �������� (�������� "SphereMesh'/Game/PathToYourSphereMesh.SphereMesh'" �� ��� ������)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	// ���������, ������� �� ��������� ����������� �����
	if (SphereMeshAsset.Succeeded())
	{
		SphereMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	}

	// ������������� ��������� ����� �� �������
	SphereMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	SphereMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));  // ��������, ��������� ����� ��� ��������
	SphereMeshComponent->SetEnableGravity(false);

	AIControllerClass = ATestPlayerAIController::StaticClass();
}


// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	SpawnDefaultController();
	
	// ��������� ��� �����������
	AController* MyController = GetController();
	if (MyController)
	{
		PlayerAIController = Cast<ATestPlayerAIController>(MyController);

		if (PlayerAIController)
		{
			FVector TargetLocation = FVector(-350, 0, 90); // ���� ������ ����������
			PlayerAIController->SetTargetLocation(TargetLocation);
		}
	}
	else
	{
		// ����� ����������, ���� ����������� ���
		UE_LOG(LogTemp, Warning, TEXT("MyController is nullptr"));
	}

}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
// void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
// 
// }

