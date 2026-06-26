// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddTwoEvent, uint8, Number);

UENUM(BlueprintType)
enum class ELanguage : uint8
{
	EL_Auto		UMETA(DisplayName = "Auto-Detect"),
	EL_English	UMETA(DIsplayName = "English"),
	EL_Italian	UMETA(DisplayName = "Italian")
};

USTRUCT(BlueprintType)
struct FStructure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QueryName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 Arity = 0;
};

UCLASS()
class UE_EXERCISES_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	FString TestString = "Init";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	ELanguage TestEnumLanguage = ELanguage::EL_Auto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	FStructure TestStructure;

	UPROPERTY(BlueprintAssignable, Category = "Test")
	FAddTwoEvent AddTwoEvent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Say no", keywords = "Say no"), Category = "Test")
	void SayNo(FString Test);

	UFUNCTION(BlueprintCallable, Category = "Test")
	uint8 AddTwo(uint8 Number);
};
