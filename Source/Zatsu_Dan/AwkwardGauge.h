// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "AwkwardGauge.generated.h"

/**
 * 気まずいゲージ
 */
UCLASS(Blueprintable)
class ZATSU_DAN_API UAwkwardGauge : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/**気まずいゲージのImage*/
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
	/**最大値*/
	UPROPERTY(Blueprintable, EditAnywhere, Category = "Stats")
	float MaxValue;
	/**減少速度*/
	UPROPERTY(Blueprintable, EditAnywhere, Category = "Stats")
	float DecreaseRate = 0.1f;
	/**UIのTickに相当する関数*/
	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime)override;
private:
	bool bIsStarted = false;
};
