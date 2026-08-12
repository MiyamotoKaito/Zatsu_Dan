// Fill out your copyright notice in the Description page of Project Settings.


#include "AwkwardGauge.h"

void UAwkwardGauge::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
	if (bIsStarted)
	{
		Super::NativeTick(Geometry, DeltaTime);
	}
}
