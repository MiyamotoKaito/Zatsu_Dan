// Fill out your copyright notice in the Description page of Project Settings.


#include "ChoiceButton.h"

#include "Choice.h"

UChoiceButton::UChoiceButton()
{
	OnClicked.AddDynamic(this, &UChoiceButton::HandleClicked);
}

FResult UChoiceButton::GetResult()
{
	return Result;
}

void UChoiceButton::HandleClicked()
{
	OnAwkwardGaugeEmpty.Broadcast(GetResult());
}
