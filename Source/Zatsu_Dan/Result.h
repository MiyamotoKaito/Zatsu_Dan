#pragma once

#include "CoreMinimal.h"
#include "Result.generated.h"

/*
 *　会話したあとの結果
 */
USTRUCT(BlueprintType)
struct FResult
{
	GENERATED_BODY()
	
public:
	FResult();
	/* Listenerの返答 */
	UPROPERTY(EditAnywhere)
	FString Response;
	
	/* Buttonに表示されるテキスト */
	UPROPERTY(EditAnywhere)
	FString Text;

	/* ゲージの変更値 */
	UPROPERTY(EditAnywhere)
	int32 Value;
};
