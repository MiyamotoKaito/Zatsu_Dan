// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "AwkwardGauge.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAwkwardGaugeEmptySignature);

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
	void SetValue(float InMaxValue);
	
	/** 気まずいゲージが０になったら発火するイベント(BluePrintで登録する)*/
	UPROPERTY(BlueprintAssignable, Category = "Stats")
	FOnAwkwardGaugeEmptySignature OnGaugeEmpty;
protected:
	/**気まずいゲージのImage*/
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
	/**最大値*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite,  Category = "Stats")
	float MaxValue;
	/**UIのTickに相当する関数*/
	virtual void NativeTick(const FGeometry& Geometry, float DeltaTime)override;
private:
	void UpdateProgressBar();
	bool bIsStarted = false;
	float CurrentValue;
};
