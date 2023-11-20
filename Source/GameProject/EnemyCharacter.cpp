// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Components/SphereComponent.h"

AEnemyCharacter::AEnemyCharacter() {
    TriggerArea = this->FindComponentByClass<USphereComponent>();
    TriggerArea->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnOverlapBegin); 
}
void AEnemyCharacter::BeginPlay() {
    Super::BeginPlay();

}

void AEnemyCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    if (OtherActor && (OtherActor != this))
    {   
        if(OtherActor->IsA(APlayerCharacter::StaticClass())){
            PlayerActor = OtherActor;
        }
    }
}
