// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTChasePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//AActor* PlayerActor = OwnerComp->GetValueAsObject(TEXT("PlayerActor"));

	return EBTNodeResult::Succeeded;
}