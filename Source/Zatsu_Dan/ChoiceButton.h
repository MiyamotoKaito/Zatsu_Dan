// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Result.h"
#include "Components/Button.h"
#include "ChoiceButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChoiceButtonClicked, FResult, result);

/**
 * クリックしたときにResultを返すボタン
 */
UCLASS()
class ZATSU_DAN_API UChoiceButton : public UButton
{
	GENERATED_BODY()

public:
	UChoiceButton();
	
	UPROPERTY(BlueprintAssignable, Category = "TalkSystem")
	FOnChoiceButtonClicked OnAwkwardGaugeEmpty;
	
	FResult GetResult();
protected:
	
private:
	void HandleClicked();
	UPROPERTY(EditAnywhere, Category = "Result")
	FResult Result;
};
