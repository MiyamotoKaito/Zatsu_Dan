#include "AwkwardGauge.h"

void UAwkwardGauge::SetValue(float InMaxValue)
{
	MaxtValue = InMaxValue;
	CurrentValue = MaxtValue;
	UpdateProgressBar();
}

void UAwkwardGauge::NativeTick(const FGeometry& Geometry, float DeltaTime)
{
	Super::NativeTick(Geometry, DeltaTime);
	
	if (!bIsStarted)
	{
		return;
	}
	
	CurrentValue -= DeltaTime;
	
	if (CurrentValue < 0.0f)
	{
		CurrentValue = 0.0f;
		//　二重に発火するのを防ぐためにfalseに
		bIsStarted = false;
		// イベント発火
		OnGaugeEmpty.Broadcast();
	}
	
	UpdateProgressBar();
}

void UAwkwardGauge::UpdateProgressBar()
{
	ProgressBar->SetPercent(CurrentValue / MaxtValue);
}
