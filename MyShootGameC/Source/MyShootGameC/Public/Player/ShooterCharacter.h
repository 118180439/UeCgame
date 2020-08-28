// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class MYSHOOTGAMEC_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// ���������ɫ�����Ե�Ĭ��ֵ
	AShooterCharacter();

protected:
	// �ڱ�����ʼʱ���û��ߵ���
	virtual void BeginPlay() override;

public:	
	// ��ÿһ֡
	virtual void Tick(float DeltaTime) override;

	// ����󶨹���
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ǰ���ƶ���
	void MoveForward(float value);

	// �����ƶ���
	void MoveRight(float value);

protected:
	//������� ��¶���ɱ༭
	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* Camera1P;
	//������һ�˳�ģ�� ��¶���ɱ༭
	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;

};
