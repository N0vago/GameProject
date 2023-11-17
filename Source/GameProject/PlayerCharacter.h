// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API APlayerCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
	public:
		APlayerCharacter();
		void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

		virtual void Tick(float DeltaSeconds) override;

		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

		UFUNCTION(BlueprintPure)
		bool Death() const;

		bool bIsAttacking;
	protected:
		virtual void BeginPlay() override;

		class UBoxComponent* HitBox;
	private:
		UPROPERTY(EditAnywhere)
		float CharacterSpeed = 200.f;

		UPROPERTY(EditAnywhere)
		float AttackDamage = 20.f;

		UPROPERTY(EditDefaultsOnly)
		float MaxHealthPoints = 100.f;

		UPROPERTY(VisibleAnywhere)
		float HealthPoints;

		void Attack();

		void UpdatePlayerRotation();

		void MoveRight(float Value);

		void HitCheck();

		void SetUpAttacking();

		void EnableMovement();

};
