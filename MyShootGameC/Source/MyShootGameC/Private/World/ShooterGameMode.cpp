// Copyright Epic Games, Inc. All Rights Reserved.


#include "World/ShooterGameMode.h" //路径要对应文件夹名称
#include "Player/ShooterCharacter.h" //导入角色父类
#include "Player/ShooterPlayerController.h" //导入玩家控制器
#include "Player/ShooterPlayerState.h" //导入游戏状态
#include "World/ShooterGameState.h" //导入游戏状态
#include "Player/ShooterSpectatorPawn.h" //导入旁观者
#include "UI/ShooterHUD.h" //导入界面

AShooterGameMode::AShooterGameMode() //:: 实现 头文件（.h 文件）中的方法 -> 构造函数
{
	static ConstructorHelpers::FClassFinder<AShooterCharacter> PlayPwonOB(TEXT("/Game/Blueprints/Pawns/PlayerPawn")); //找到指定的蓝图类 同时 赋值名称为 PlayPwonOB    /Game路径是UE4默认的
	//*****************设置游戏模式默认值 - 开始 ***********************
    // =号 前就是配置的系统默认参数名 , =号 后面就是自定义的对象
	DefaultPawnClass = PlayPwonOB.Class; //将 OB 类 反射到 Pawn 的类    
	PlayerControllerClass = AShooterPlayerController::StaticClass(); //导入玩家控制器  已存在C++类的引用 使用构造函数::StaticClass()
	PlayerStateClass = AShooterPlayerState::StaticClass(); //导入玩家状态
	GameStateClass = AShooterGameState::StaticClass(); // 导入游戏状态
	SpectatorClass = AShooterSpectatorPawn::StaticClass(); // 导入旁观者
	HUDClass = AShooterHUD::StaticClass(); // 导入界面
	//*****************设置游戏模式默认值 - 结束 ***********************


}

