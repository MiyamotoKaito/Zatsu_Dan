// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenerBase.h"

AListenerBase::AListenerBase()
{
	// 聞く側は自前の毎フレーム処理を持たない
	PrimaryActorTick.bCanEverTick = false;
}
