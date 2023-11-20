// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletonAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
void ASkeletonAIController::Tick(float DeltaTime) {
    if(SkeletonBT) {
        RunBehaviorTree(SkeletonBT);
        GetBlackboardComponent()->SetValueAsObject("PlayerActor", Cast<AEnemyCharacter>(GetOwner())->PlayerActor);
    }
}