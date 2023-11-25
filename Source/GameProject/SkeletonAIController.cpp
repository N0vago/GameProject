// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletonAIController.h"
#include "EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
void ASkeletonAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    FVector& CurrentVelocity = OwnerCharacter->GetCharacterMovement()->Velocity;
    CurrentVelocity *= AISpeed;

}

void ASkeletonAIController::BeginPlay()
{
    Super::BeginPlay();
    if(SkeletonBT) {
        RunBehaviorTree(SkeletonBT);
        OwnerCharacter = Cast<AEnemyCharacter>(GetPawn());
    }

}
void ASkeletonAIController::OnEnemyOverlapBegin(AActor* OtherActor) {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (TEXT("Overlapping actor: %s"), *(OtherActor->GetActorLabel(false))));
    GetBlackboardComponent()->SetValueAsObject(TEXT("PlayerActor"), OtherActor);
    if(FVector::Dist(Cast<APawn>(OtherActor)->GetActorLocation(), GetPawn()->GetActorLocation()) <= 80.f)
    {
        OwnerCharacter->Attack();
    }
}

void ASkeletonAIController::OnEnemyOverlapEnd() {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (TEXT("Overlapping end")));
    GetBlackboardComponent()->ClearValue(TEXT("PlayerActor"));
}