// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Interface/ABGameInterface.h"
#include "ABGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameMode, public IABGameInterface
{
	GENERATED_BODY()
	
public:
	AABGameMode();

	virtual FTransform GetRandomStartTransform() const;
	virtual void OnPlayerKilled(AController* Killer, AController* KilledPlayer, APawn* KilledPawn);

	//virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	//virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	//virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void StartPlay() override;

protected:
	virtual void PostInitializeComponents() override;
	virtual void DefaultGameTimer();
	void FinishMatch();

	FTimerHandle GameTimerHandle;

protected:
	TArray<TObjectPtr<class APlayerStart>> PlayerStartArray;
};
