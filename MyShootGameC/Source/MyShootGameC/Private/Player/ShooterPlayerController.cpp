// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"
#include "Player/ShooterPlayerCameraManager.h"

AShooterPlayerController::AShooterPlayerController() //:: ʵ�� ͷ�ļ���.h �ļ����еķ��� -> ���캯��
{
	//����������
	PlayerCameraManagerClass = AShooterPlayerCameraManager::StaticClass(); //�Ѵ���C++�������

}

