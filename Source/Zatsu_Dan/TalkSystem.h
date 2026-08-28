// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AwkwardGauge.h"
#include "Choice.h"
#include "ListenerBase.h"
#include "SpeakerBase.h"
#include "Components/ActorComponent.h"
#include "TalkSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAwkwardGaugeEmpty);

/**
 * 会話(神)クラス
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ZATSU_DAN_API UTalkSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * ゲームスタート
	 */
	UTalkSystem();
	/** 
	 * レベルに配置されているキャラクターを取得する 
	 */
	UFUNCTION(BlueprintCallable, Category = "TalkSystem")
	void SetPeople(ASpeakerBase* SpeakerBase,
		AListenerBase* ListenerBase,
		UAwkwardGauge* Gauge);
	/**
	 * 会話スタート
	 * BPで呼べ、C++で呼ぶなカス
	 */
	UFUNCTION(BlueprintCallable, Category = "TalkSystem")
	void StartTalk();
	/**
	 * 会話を止める
	 * BPで呼べ、C++で呼ぶなカス
	 */
	UFUNCTION(BlueprintCallable, Category = "TalkSystem")
	void StopTalk();
	/**
	 * 気まずいゲージを増減させる
	 * @param Amount 
	 */
	UFUNCTION(BlueprintCallable, Category = "TalkSystem")
	void ModifyAwkward(float Amount);
	
	/**
	 * 気まずいゲージが０になった時のデリゲート
	 */
	UPROPERTY(BlueprintAssignable, Category = "TalkSystem")
	FOnAwkwardGaugeEmpty OnAwkwardGaugeEmpty;
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime,ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TalkSystem")
	float MaxAwkward = 30.0f;
private:
	void SetAwkward(float NewValue);
	
	TObjectPtr<ASpeakerBase> Speaker;
	TObjectPtr<AListenerBase> Listener;
	TObjectPtr<UAwkwardGauge> AwkwardGauge;
	
	TObjectPtr<UChoice> Choice;
	
	float CurrentAwkward = 0.0f;
	bool bIsTalking = false;
};
