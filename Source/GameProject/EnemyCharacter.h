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
	AEnemyCharacter();
	AActor* PlayerActor;
	protected:
	class USphereComponent* TriggerArea;
	virtual void BeginPlay() override;

	private:
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
