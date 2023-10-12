// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterMovementComponent.generated.h"

class FABSavedMove_Character : public FSavedMove_Character
{
	typedef FSavedMove_Character Super;
public:
	virtual void Clear() override;
	virtual void SetInitialPosition(ACharacter* Character) override;
	virtual uint8 GetCompressedFlags() const override;

	uint8 bPressedTeleport : 1;
	uint8 bDidTeleport : 1;
};

class FABNetworkPredictionData_Client_Character : public FNetworkPredictionData_Client_Character
{
	typedef FNetworkPredictionData_Client_Character Super;
public:
	FABNetworkPredictionData_Client_Character(const UCharacterMovementComponent& ClientMovement);
	virtual FSavedMovePtr AllocateNewMove() override;
};

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UABCharacterMovementComponent();

	void SetTeleportCommand();

protected:
	virtual class FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	virtual void ABTeleport();
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

public:
	uint8 bPressedTeleport : 1;
	uint8 bDidTeleport : 1;

protected:
	UPROPERTY()
	float TeleportOffset;
	
	UPROPERTY()
	float TeleportCooltime;
};
