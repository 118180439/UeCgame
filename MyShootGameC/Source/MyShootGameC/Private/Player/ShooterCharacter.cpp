// Fill out your copyright notice in the Description page of Project Settings.
// �ڡ���Ŀ���á��ġ�˵����ҳ����д���İ�Ȩ������


#include "Player/ShooterCharacter.h"

// Sets default values
// ����Ĭ��ֵ
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ַ�����Ϊÿ֡����Tick�������������Ҫ�����Թر������������
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
// ����Ϸ��ʼ������ʱ����
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
// ����ÿһ֡
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ����󶨹���
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

