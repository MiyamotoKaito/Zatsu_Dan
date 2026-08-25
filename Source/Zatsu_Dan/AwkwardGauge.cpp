#include "AwkwardGauge.h"

void UAwkwardGauge::UpdateProgressBar(float InMaxValue)
{
	ProgressBar->SetPercent(InMaxValue);
}