#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Engine/Camera.h"
#include"Ground.h"
#include"TankHead.h"
#include "Engine/SphereCollider.h"

namespace
{
	const float ColliderSize = 1.2f;//�����蔻��̃T�C�Y
	const float tankSpeed = 0.05f;//�^���N�̑��x
	const double enemyKillSpeed = 0.005;//�G�ɐڐG�����ۂɉ��Z����X�s�[�h
	const XMFLOAT3 FixedCamera = { 0, 20, -20 };//�Œ�J�����ʒu
	const XMFLOAT3 FixedTarget = { 0,0,0 };//�Œ�J�����̏œ_
	const XMFLOAT3 camposPlus = { 0,15,-10 };//TPS_NO_ROT�ɉ��Z
	const XMVECTOR vectorEye = { 0, 5, -10, 0 };//TPS���_
}

//�J��������
enum CAM_TYPE
{
	FIXED_TYPE,//�Œ�
	TPS_NO_ROT_TYPE,//�O�l�̉�]�Ȃ�
	TPS_TYPE,//�O�l��
	FPS_TYPE,//��l��
	MAX//�ԕ��i�`�F�b�N�p�̒l�j
};


Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hmodel_(-1), front_({ 0,0,1,0 }), speed_(tankSpeed),camState_( CAM_TYPE::FIXED_TYPE)
{
}

Tank::~Tank()
{
	
}

void Tank::Initialize()
{
	hmodel_ = Model::Load("Model\\TankBody2.fbx");
	assert(hmodel_ >= 0);
	Instantiate<TankHead>(this);//�^���Ncpp�Ƀ^���N�w�b�h��������
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), ColliderSize);
	AddCollider(collision);
}

void Tank::Update()
{

	XMMATRIX rotY = XMMatrixIdentity();//�s��@//XMMatrixIdentity�͉������Ȃ��s��
	XMVECTOR move{0,0,0,0};//xyz�S��0
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	
	if (Input::IsKey(DIK_W))
	{
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S))
	{
		dir = -1.0;
	}
	

	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}

	//��]�s������߂�
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//y���Ɏ��@�̉�]������������]������s��
	//�x�N�g���̉�]���ʂ����߂�
	rotVec = XMVector3TransformCoord(front_, rotY);//�i�x�N�g��front���s��rotY�ŕό`�j
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//���@�̏ꏊ


	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);//XMStoreFloat3(�s��,�x�N�g��)



	//Debug::Log(transform_.rotate_.y, true);
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);
	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
	}

	if (Input::IsKeyDown(DIK_Z))//�^���N�̎��_�ύX
	{
		camState_++;
		//camState_ = (++camState_) % (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

		switch (camState_)
		{
		case CAM_TYPE::FIXED_TYPE:
		{
			Camera::SetPosition(FixedCamera);
			Camera::SetTarget(FixedTarget);
			break;
		}

		case CAM_TYPE::TPS_NO_ROT_TYPE:
		{
			XMFLOAT3 campos = transform_.position_;
			campos.y = transform_.position_.y + camposPlus.y;
			campos.z = transform_.position_.z + camposPlus.z;
			Camera::SetPosition(campos);
			Camera::SetTarget(transform_.position_);
			break;
		}
		case CAM_TYPE::TPS_TYPE:
		{
			Camera::SetTarget(transform_.position_);
			XMVECTOR vEye{ vectorEye };
			vEye = XMVector3TransformCoord(vEye, rotY);
			XMFLOAT3 campos;
			XMStoreFloat3(&campos, pos + vEye);
			Camera::SetPosition(campos);
			break;
		}


		case CAM_TYPE::FPS_TYPE:
			Camera::SetPosition(transform_.position_);
			XMFLOAT3 camTarget;
			XMStoreFloat3(&camTarget, pos + move);
			Camera::SetPosition(camTarget);
			break;
		default:
			break;
		}
	
	}


void Tank::Draw()
{
	Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);
	
}

void Tank::Release()
{
}

void Tank::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		speed_ += enemyKillSpeed;//Enemy�ƂԂ���ƃX�s�[�h�A�b�v
	}
}
