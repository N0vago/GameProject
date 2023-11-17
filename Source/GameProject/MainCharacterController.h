// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMainCharacterController : public APlayerController
{

	GENERATED_BODY()
	AMainCharacterController();
	private:
	protected:
	virtual void BeginPlay() override;
};
