// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ShooterGameMode.generated.h" //UE4�Դ����䷽���������ڵ�����Դ������

/**
 * ��Ҫ������Ϸģʽ�ĸ���
 */
UCLASS()  
class MYSHOOTGAMEC_API AShooterGameMode : public AGameMode  //�޸� AGameModeBase ��Ϊ AGameMode,������������Ҫ�����
{
	GENERATED_BODY()

public:
	AShooterGameMode(); //���캯��
};
