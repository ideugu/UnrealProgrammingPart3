// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABFountain.generated.h"

UCLASS()
class ARENABATTLE_API AABFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	TObjectPtr<class UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	TObjectPtr<class UStaticMeshComponent> Water;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnActorChannelOpen(class FInBunch& InBunch, class UNetConnection* Connection) override;
	virtual bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override;
	virtual void PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker) override;

	UPROPERTY(ReplicatedUsing = OnRep_ServerRotationYaw)
	float ServerRotationYaw;

	UPROPERTY(ReplicatedUsing = OnRep_ServerLightColor)
	FLinearColor ServerLightColor;
	//UPROPERTY(Replicated)
	//TArray<float> BigData;

	UFUNCTION()
	void OnRep_ServerRotationYaw();

	UFUNCTION()
	void OnRep_ServerLightColor();

	float RotationRate = 30.0f;
	float ClientTimeSinceUpdate = 0.0f;
	float ClientTimeBetweenLastUpdate = 0.0f;

	//float BigDataElement = 0.0f;

};
