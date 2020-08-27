// Fill out your copyright notice in the Description page of Project Settings.
// 在“项目设置”的“说明”页中填写您的版权声明。


#include "Player/ShooterCharacter.h"

// Sets default values
// 设置默认值
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 将此字符设置为每帧调用Tick（）。如果不需要，可以关闭它以提高性能
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
// 在游戏开始或生成时调用
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
// 调用每一帧
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 输入绑定功能
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

