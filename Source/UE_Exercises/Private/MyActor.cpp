// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Hello World!"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::SayNo(FString Test)
{
	UE_LOG(LogTemp, Log, TEXT("No to %s"), *Test);
}

uint8 AMyActor::AddTwo(uint8 Number)
{
	Number = Number + 2;

	UE_LOG(LogTemp, Warning, TEXT("Bound: %s"), AddTwoEvent.IsBound() ? TEXT("YES") : TEXT("NO"));

	AddTwoEvent.Broadcast(Number);

	return Number;
}

