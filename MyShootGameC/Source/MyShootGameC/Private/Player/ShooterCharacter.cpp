// Fill out your copyright notice in the Description page of Project Settings.
// 在“项目设置”的“说明”页中填写您的版权声明。

#include "MyShootGameC.h"
#include "Player/ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h" //解决 GetCharacterMovement() 方法 返回值未定义
#include "Components/CapsuleComponent.h" //解决 GetCapsuleComponent() 方法 返回值未定义
#include "Camera/CameraComponent.h"//解决 UCameraComponent() 方法 返回值未定义

// Sets default values
// 设置默认值
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 将此字符设置为每帧调用Tick（）。如果不需要，可以关闭它以提高性能
	PrimaryActorTick.bCanEverTick = false;

	//创建默认相机 并命名为 PawnCamera1P
	Camera1P = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera1P"));
	//将相机挂载到 根组件上
	Camera1P ->SetupAttachment(GetCapsuleComponent());
	//设置位置
	Camera1P ->SetRelativeLocation(FVector(0.0f,0.0f,BaseEyeHeight));//眼睛高度
	Camera1P ->bUsePawnControlRotation = true;

	//加入第一人称手臂 mesh
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PawnMesh1P"));
	Mesh1P ->SetupAttachment(Camera1P);
	Mesh1P ->bOnlyOwnerSee = true; //仅自己可见
	Mesh1P ->bOwnerNoSee = false;
	Mesh1P ->bReceivesDecals = false;
	Mesh1P ->bCastDynamicShadow = false;
	//骨骼动画的pose的更新只发生在渲染时
	Mesh1P ->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	//把第一人称MESH 的更新组 设置在物理之前更新的组
	Mesh1P->SetCollisionObjectType(ECC_Pawn);
	Mesh1P->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh1P->SetCollisionResponseToAllChannels(ECR_Ignore);
	//设置第一人称mesh手臂位置
	Mesh1P->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f - 86.0f - BaseEyeHeight));//原点-模型便宜位置-眼睛高度

	//前后左右的移动验证


	//对自己隐藏第三人称模型
	//对第三人称mesh 进行可见性、贴花投射  - 关闭它以提高性能
	GetMesh()->bOnlyOwnerSee = false;
	GetMesh()->bOwnerNoSee = true; //自己不可见
	GetMesh()->bReceivesDecals = false;

	//设置模型 碰撞类型
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	//设置物理
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//设置碰撞
	GetMesh()->SetCollisionResponseToChannel(COLISION_PROJECTILE, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(COLISION_PICKUP, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(COLISION_WEAPON, ECR_Ignore);

	//设置胶囊体的碰撞 只对于子弹进行反应
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_PROJECTILE, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_PICKUP, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLISION_WEAPON, ECR_Ignore);

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
	//消息 或 函数 绑定   &方法 -> 访问存储位置
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this, &AShooterCharacter::MoveRight);

	//设置鼠标移动
	PlayerInputComponent->BindAxis(TEXT("Turn"),this, &AShooterCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this, &AShooterCharacter::AddControllerPitchInput);

}
// 前后移动功能
void AShooterCharacter::MoveForward(float value) 
{
	if (Controller != nullptr)
	{
		//获取人物前进的方向，注意是否对前进方向有角度限制
		bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
		FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);//获取X轴坐标
		AddMovementInput(Direction, value);
	}
}
// 左右移动功能
void AShooterCharacter::MoveRight(float value)
{
	/*bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
	FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();*/
	//获取人物左右移动的方向
	FRotator Rotation = GetActorRotation();
	FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);//获取Y轴坐标
	AddMovementInput(Direction, value);
}
