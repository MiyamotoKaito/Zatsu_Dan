// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkSystem.h"

UTalkSystem::UTalkSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bCanEverTick = false; 
	
	CurrentAwkward = MaxAwkward;
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

void UTalkSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!bIsTalking)
	{
		return;
	}
	
	CurrentAwkward -= DeltaTime;
	
	if (CurrentAwkward < 0.0f)
	{
		CurrentAwkward = 0.0f;
		//　二重に発火するのを防ぐためにfalseに
		bIsTalking = false;
		// イベント発火
		OnAwkwardGaugeEmpty.Broadcast();
	}
	
	SetAwkward(CurrentAwkward / MaxAwkward);
}

void UTalkSystem::SetAwkward(float NewValue)
{
	AwkwardGauge->UpdateProgressBar(NewValue);
}

