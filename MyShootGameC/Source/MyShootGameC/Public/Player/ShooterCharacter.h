// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class MYSHOOTGAMEC_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// 设置这个角色的属性的默认值
	AShooterCharacter();

protected:
	// 在比赛开始时调用或者当了
	virtual void BeginPlay() override;

public:	
	// 称每一帧
	virtual void Tick(float DeltaTime) override;

	// 输入绑定功能
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
