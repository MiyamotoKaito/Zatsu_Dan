#pragma once
#include "CoreMinimal.h"
#include "GameStateType.generated.h"

/**
 *　ゲームの状態を全て管理するステート
 */
UENUM(BlueprintType)
enum class  EGameStateType  : uint8
{
	Title			UMETA(DisplayName = "タイトル"),
	TitleStart		UMETA(DisplayName = "タイトル開始"),
	TitleEnd		UMETA(DisplayName = "タイトル終了"),
	
	InGameAnimStart UMETA(DisplayName = "インゲームアニメーション開始"),
	InGameAnimEnd	UMETA(DisplayName = "インゲームアニメーション終了"),
	
	InGameTalkStart UMETA(DisplayName = "会話スタート"),
	InGameTalking	UMETA(DisplayName = "会話中"),
	InGameTalkEnd	UMETA(DisplayName = "会話終了"),
	
	Ending			UMETA(DisplayName = "エンディング")
};
