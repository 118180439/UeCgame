// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"
#include "Player/ShooterPlayerCameraManager.h"

AShooterPlayerController::AShooterPlayerController() //:: 实现 头文件（.h 文件）中的方法 -> 构造函数
{
	//添加相机管理
	PlayerCameraManagerClass = AShooterPlayerCameraManager::StaticClass(); //已存在C++类的引用

}

