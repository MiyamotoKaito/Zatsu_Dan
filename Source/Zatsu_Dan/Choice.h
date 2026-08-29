// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChoiceButton.h"
#include "Blueprint/UserWidget.h"
#include "Choice.generated.h"

/**
 * 選択肢UIクラス
 */
UCLASS()
class ZATSU_DAN_API UChoice : public UUserWidget
{
	GENERATED_BODY()
public:
	/* ボタンの配列 */
	UPROPERTY(BlueprintType, EditAnywhere, Category = "Button")
	TArray<TObjectPtr<UChoiceButton>> ChoiceButtons;
};
