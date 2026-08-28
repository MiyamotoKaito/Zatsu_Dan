// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkSystem.h"

UTalkSystem::UTalkSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTalkSystem::SetPeople(ASpeakerBase* SpeakerBase,
	AListenerBase* ListenerBase,
	UAwkwardGauge* Gauge)
{
	Speaker = SpeakerBase;
	Listener = ListenerBase;
	AwkwardGauge = Gauge;
	
	if (Speaker == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpeakerがNullです"));
	}
	if (Listener == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ListenerがNullです"))
	}
	if (AwkwardGauge == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("気まずいゲージがNullです"));
	}
	
	// ゲージの初期表示を現在値に合わせる
	SetAwkward(CurrentAwkward);
}

void UTalkSystem::StartTalk()
{
	bIsTalking = true;
}

void UTalkSystem::StopTalk()
{
	bIsTalking = false;
}

void UTalkSystem::ModifyAwkward(float Amount)
{
	SetAwkward(CurrentAwkward + Amount);
}

void UTalkSystem::BeginPlay()
{
	Super::BeginPlay();
}

void UTalkSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!bIsTalking)
	{
		return;
	}
	
	SetAwkward(CurrentAwkward += DeltaTime);
	
	if (CurrentAwkward > MaxAwkward)
	{
		//　二重に発火するのを防ぐためにfalseに
		bIsTalking = false;
		// イベント発火
		OnAwkwardGaugeEmpty.Broadcast();
	}
}

void UTalkSystem::SetAwkward(float NewValue)
{
	CurrentAwkward = FMath::Clamp(NewValue, 0.0f, MaxAwkward);
	
	if (AwkwardGauge == nullptr)
	{
		return;
	}
	
	// ProgressBarは0〜1の割合を受け取るので正規化して渡す
	AwkwardGauge->UpdateProgressBar(CurrentAwkward / MaxAwkward);
}
