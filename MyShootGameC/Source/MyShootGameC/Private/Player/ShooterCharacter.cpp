// Fill out your copyright notice in the Description page of Project Settings.
// �ڡ���Ŀ���á��ġ�˵����ҳ����д���İ�Ȩ������

#include "MyShootGameC.h"
#include "Player/ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h" //��� GetCharacterMovement() ���� ����ֵδ����
#include "Components/CapsuleComponent.h" //��� GetCapsuleComponent() ���� ����ֵδ����
#include "Camera/CameraComponent.h"//��� UCameraComponent() ���� ����ֵδ����

// Sets default values
// ����Ĭ��ֵ
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ַ�����Ϊÿ֡����Tick�������������Ҫ�����Թر������������
	PrimaryActorTick.bCanEverTick = false;

	//����Ĭ����� ������Ϊ PawnCamera1P
	Camera1P = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera1P"));
	//��������ص� �������
	Camera1P ->SetupAttachment(GetCapsuleComponent());
	//����λ��
	Camera1P ->SetRelativeLocation(FVector(0.0f,0.0f,BaseEyeHeight));//�۾��߶�
	Camera1P ->bUsePawnControlRotation = true;

	//�����һ�˳��ֱ� mesh
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PawnMesh1P"));
	Mesh1P ->SetupAttachment(Camera1P);
	Mesh1P ->bOnlyOwnerSee = true; //���Լ��ɼ�
	Mesh1P ->bOwnerNoSee = false;
	Mesh1P ->bReceivesDecals = false;
	Mesh1P ->bCastDynamicShadow = false;
	//����������pose�ĸ���ֻ��������Ⱦʱ
	Mesh1P ->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	//�ѵ�һ�˳�MESH �ĸ����� ����������֮ǰ���µ���
	Mesh1P->SetCollisionObjectType(ECC_Pawn);
	Mesh1P->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh1P->SetCollisionResponseToAllChannels(ECR_Ignore);
	//���õ�һ�˳�mesh�ֱ�λ��
	Mesh1P->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - 86.0f - BaseEyeHeight));//ԭ��-ģ�ͱ���λ��-�۾��߶�

	//ǰ�����ҵ��ƶ���֤


	//���Լ����ص����˳�ģ��
	//�Ե����˳�mesh ���пɼ��ԡ�����Ͷ��  - �ر������������
	GetMesh()->bOnlyOwnerSee = false;
	GetMesh()->bOwnerNoSee = true; //�Լ����ɼ�
	GetMesh()->bReceivesDecals = false;

	//����ģ�� ��ײ����
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	//��������
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//������ײ
	GetMesh()->SetCollisionResponseToChannel(COLISION_PROJECTILE, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(COLISION_PICKUP, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(COLISION_WEAPON, ECR_Ignore);

	//���ý��������ײ ֻ�����ӵ����з�Ӧ
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_PROJECTILE, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_PICKUP, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_WEAPON, ECR_Ignore);

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
	//��Ϣ �� ���� ��   &���� -> ���ʴ洢λ��
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this, &AShooterCharacter::MoveRight);

	//��������ƶ�
	PlayerInputComponent->BindAxis(TEXT("Turn"),this, &AShooterCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this, &AShooterCharacter::AddControllerPitchInput);

}
// ǰ���ƶ�����
void AShooterCharacter::MoveForward(float value) 
{
	if (Controller != nullptr)
	{
		//��ȡ����ǰ���ķ���ע���Ƿ��ǰ�������нǶ�����
		bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
		FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);//��ȡX������
		AddMovementInput(Direction, value);
	}
}
// �����ƶ�����
void AShooterCharacter::MoveRight(float value)
{
	/*bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
	FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();*/
	//��ȡ���������ƶ��ķ���
	FRotator Rotation = GetActorRotation();
	FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);//��ȡY������
	AddMovementInput(Direction, value);
}
