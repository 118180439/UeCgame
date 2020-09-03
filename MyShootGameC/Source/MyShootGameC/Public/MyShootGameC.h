// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once //避免被引入多次

#include "CoreMinimal.h"

//宏定义 - 碰撞通道
//子弹碰撞
#define COLISION_PROJECTILE  ECC_GameTraceChannel1
//拾取碰撞
#define COLISION_PICKUP      ECC_GameTraceChannel2
//武器碰撞
#define COLISION_WEAPON      ECC_GameTraceChannel3