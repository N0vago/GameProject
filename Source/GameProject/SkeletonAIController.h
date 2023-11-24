// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SkeletonAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API ASkeletonAIController : public AAIController
{
	GENERATED_BODY()
	public:
	virtual void Tick(float DeltaTime) override;

	void OnEnemyOverlapBegin(AActor* OtherActor);

	void OnEnemyOverlapEnd();
	protected:
	virtual void BeginPlay() override;
	private:
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* SkeletonBT;



};
