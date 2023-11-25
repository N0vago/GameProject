// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/PrimitiveComponent.h"
#include "MainCharacterController.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbook.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CuttingDamageType.h"
#include "D:\Developing\Soft\UE_5.1\Engine\Plugins\2D\Paper2D\Source\Paper2D\Classes\PaperFlipbookComponent.h"

APlayerCharacter::APlayerCharacter() {
    PrimaryActorTick.bCanEverTick = true;
    bIsAttacking = false;

}
void APlayerCharacter::BeginPlay() {
    Super::BeginPlay();
    HealthPoints = MaxHealthPoints;
    HitBox = this->FindComponentByClass<UBoxComponent>();
}
void APlayerCharacter::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);
    UpdatePlayerRotation();
    HitBox->SetHiddenInGame(!bIsAttacking);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAction("Jump", IE_Pressed,this,&ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released,this,&ACharacter::StopJumping);
    PlayerInputComponent->BindAction("Attack", IE_Pressed, this,&APlayerCharacter::Attack);
}
void APlayerCharacter::MoveRight(float Value)
{
    // Add movement in that direction
    float DeltaSeconds = GetWorld()->GetDeltaSeconds();
    FVector Direction = FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value * DeltaSeconds * CharacterSpeed);

}
void APlayerCharacter::UpdatePlayerRotation() {
    FRotator currentRotation = GetSprite()->GetRelativeRotation();
    const FVector velocity = GetVelocity();

    if(velocity.X < 0.f)
        GetSprite()->SetRelativeRotation(FRotator(0.f,180.f,0.f));
    else if(velocity.X == 0.f)
        GetSprite()->SetRelativeRotation(currentRotation);
    else
        GetSprite()->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
}

void APlayerCharacter::Attack() {
    if(!(GetCharacterMovement()->IsFalling()) && !bIsAttacking){
        SetUpAttacking();
        HitCheck();
    }
}

float APlayerCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) {
    Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
    return HealthPoints -= DamageAmount;
}

void APlayerCharacter::HitCheck() {
    TArray<AActor*> HitActors;
    HitBox->GetOverlappingActors(HitActors);
    for (AActor* HitActor : HitActors)
    {
        if (HitActor && HitActor->CanBeDamaged() && HitActor != this)
        {
            UGameplayStatics::ApplyDamage(HitActor, AttackDamage, GetController(), this, UCuttingDamageType::StaticClass());
        }
    }
    
}

void APlayerCharacter::SetUpAttacking() {
    bIsAttacking = true;

    GetCharacterMovement()->DisableMovement();

    FTimerHandle Time;

    float Duration = GetSprite()->GetFlipbookLength() - 0.1;
    // Set a timer to re-enable movement after 1 second
    GetWorld()->GetTimerManager().SetTimer(Time, this, &APlayerCharacter::EnableMovement, Duration, false);

}
void APlayerCharacter::EnableMovement() {
    GetCharacterMovement()->SetMovementMode(MOVE_Walking);
    bIsAttacking = false;
}
bool APlayerCharacter::Death() const{
    return HealthPoints <= 0;
}
