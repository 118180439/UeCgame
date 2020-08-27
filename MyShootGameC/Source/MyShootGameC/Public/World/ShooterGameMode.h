// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ShooterGameMode.generated.h" //UE4自带反射方法，必须在导入资源最后加载

/**
 * 主要用于游戏模式的更改
 */
UCLASS()  
class MYSHOOTGAMEC_API AShooterGameMode : public AGameMode  //修改 AGameModeBase 改为 AGameMode,多人联机必须要改这个
{
	GENERATED_BODY()

public:
	AShooterGameMode(); //构造函数
};
