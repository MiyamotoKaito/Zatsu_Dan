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
public:
	/**
	 * 気まずいゲージの値を設定する
	 * @param InMaxValue 
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void UpdateProgressBar(float InMaxValue);

protected:
	/**気まずいゲージのImage*/
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
};
