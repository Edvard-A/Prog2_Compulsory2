// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Bullet.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionSphere) {
		CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
		CollisionSphere->InitSphereRadius(100.0f);

		RootComponent = CollisionSphere;
	}

	if (!EnemyMesh) {
		EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
		EnemyMesh->SetupAttachment(CollisionSphere);
	}

}

void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	//DOESNT WORK
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, TEXT("Overlapping!"));
	if (OtherActor->IsA(ABullet::StaticClass())) {
		//Cast<AEnemy>(OtherActor)->Destroy();
		Destroy();
	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

