// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_RotateToMovingDirection.h"
#include "SkeletonAIController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "PaperFlipbookComponent.h"

void UBTS_RotateToMovingDirection::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    UObject* PlayerObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject("PlayerActor");
    APawn* OwnerAIPawn = Cast<APawn>(OwnerComp.GetAIOwner());
    if(OwnerAIPawn ) {
        FVector2D Velocity2D(OwnerAIPawn->GetVelocity().X);

        // Check if the velocity is significant enough
        if(Velocity2D.SizeSquared() > 0.f)
        {
            // Normalize the 2D velocity vector to get the direction
            FVector2D Direction2D = Velocity2D.GetSafeNormal();

            // Calculate the angle in degrees
            float AngleInDegrees = FMath::RadiansToDegrees(atan(Direction2D.X));

            // Create a new rotator for 2D rotation (rotation about Z axis)
            FRotator NewRotation = FRotator(0, AngleInDegrees, 0);

            // Set the actor's rotation
            OwnerComp.GetAIOwner()->GetOwner()->SetActorRotation(NewRotation);
        }
    }
}