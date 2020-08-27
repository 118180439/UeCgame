// Copyright Epic Games, Inc. All Rights Reserved.


#include "World/ShooterGameMode.h" //·��Ҫ��Ӧ�ļ�������
#include "Player/ShooterCharacter.h" //�����ɫ����
#include "Player/ShooterPlayerController.h" //������ҿ�����
#include "Player/ShooterPlayerState.h" //������Ϸ״̬
#include "World/ShooterGameState.h" //������Ϸ״̬
#include "Player/ShooterSpectatorPawn.h" //�����Թ���
#include "UI/ShooterHUD.h" //�������

AShooterGameMode::AShooterGameMode() //:: ʵ�� ͷ�ļ���.h �ļ����еķ��� -> ���캯��
{
	static ConstructorHelpers::FClassFinder<AShooterCharacter> PlayPwonOB(TEXT("/Game/Blueprints/Pawns/PlayerPawn")); //�ҵ�ָ������ͼ�� ͬʱ ��ֵ����Ϊ PlayPwonOB    /Game·����UE4Ĭ�ϵ�
	//*****************������ϷģʽĬ��ֵ - ��ʼ ***********************
    // =�� ǰ�������õ�ϵͳĬ�ϲ����� , =�� ��������Զ���Ķ���
	DefaultPawnClass = PlayPwonOB.Class; //�� OB �� ���䵽 Pawn ����    
	PlayerControllerClass = AShooterPlayerController::StaticClass(); //������ҿ�����  �Ѵ���C++������� ʹ�ù��캯��::StaticClass()
	PlayerStateClass = AShooterPlayerState::StaticClass(); //�������״̬
	GameStateClass = AShooterGameState::StaticClass(); // ������Ϸ״̬
	SpectatorClass = AShooterSpectatorPawn::StaticClass(); // �����Թ���
	HUDClass = AShooterHUD::StaticClass(); // �������
	//*****************������ϷģʽĬ��ֵ - ���� ***********************


}

