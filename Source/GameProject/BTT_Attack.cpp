// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Attack.h"
#include "SkeletonAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    ASkeletonAIController* AIController = Cast<ASkeletonAIController>(OwnerComp.GetAIOwner());
    AEnemyCharacter* OwnerCharacter = Cast<AEnemyCharacter>(AIController->GetOwner());
    APawn* HeroPawn = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("PlayerActor")));
    float Distance = FVector::Dist(HeroPawn->GetActorLocation(), AIController->GetPawn()->GetActorLocation());
    if(Distance <= 80) {
        OwnerCharacter->Attack();
    }

    return EBTNodeResult::Succeeded;
}