// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTChasePlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"

EBTNodeResult::Type UBTTChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Hero = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("PlayerActor")));
	AAIController* AIController = Cast<AAIController>(OwnerComp.GetAIOwner());
	if(AIController){
		
	}

	return EBTNodeResult::Succeeded;
}