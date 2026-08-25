// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ListenerBase.generated.h"

/**
 * 話を聞く側のキャラクター
 */
UCLASS(Blueprintable)
class ZATSU_DAN_API AListenerBase : public ACharacter
{
	GENERATED_BODY()

public:
	AListenerBase();
};
