// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AEnemyCharacter : public APlayerCharacter
{
	GENERATED_BODY()
	public:
	//Enemy character constructor
	AEnemyCharacter();

	//Trigger area of enemy character
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* TriggerArea;

	//Overlapping events
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	protected:

	virtual void BeginPlay() override;

};
