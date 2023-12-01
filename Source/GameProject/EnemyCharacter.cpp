// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "SkeletonAIController.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"

AEnemyCharacter::AEnemyCharacter() {
    PrimaryActorTick.bCanEverTick = true;
    TriggerArea = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerArea"));
    TriggerArea->SetupAttachment(this->GetSprite());
    TriggerArea->InitSphereRadius(250.f);
    TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnOverlapBegin); 
    TriggerArea->OnComponentEndOverlap.AddDynamic(this, &AEnemyCharacter::OnOverlapEnd);
}
void AEnemyCharacter::BeginPlay() {
    Super::BeginPlay();
    HitBox = this->FindComponentByClass<UBoxComponent>();
}


void AEnemyCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    if (OtherActor->IsA(APlayerCharacter::StaticClass()) && (OtherActor != this))
    {   
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, (TEXT("Overlapping actor: %s"), *(OtherActor->GetActorLabel(false))));
        ASkeletonAIController* AIController = Cast<ASkeletonAIController>(GetController());
        if (AIController) {
            AIController->OnEnemyOverlapBegin(OtherActor);
        }
    }
    
}
void AEnemyCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, (TEXT("Overlapping end")));
    ASkeletonAIController* AIController = Cast<ASkeletonAIController>(GetController());
    if (AIController) {
        AIController->OnEnemyOverlapEnd();
    }
}
void AEnemyCharacter::Attack() {
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, (TEXT("Attack")));
     APlayerCharacter::HitCheck(HitBox);
    
}
