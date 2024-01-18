#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Ground.h"
#include"TankHead.h"
#include"Engine/Camera.h"

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
	:GameObject(parent, "Tank"), hmodel_(-1), front_({ 0,0,1,0 }), speed_(0.05),camState_( CAM_TYPE::FIXED_TYPE)
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
}

void Tank::Update()
{
	//��]�s������߂�
	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));;
	//�x�N�g���̉�]���ʂ����߂�
	XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);


	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}
	if (Input::IsKey(DIK_W))
	{
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S))
	{
		XMVECTOR move;
		move = speed_ * front_;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
	}
	
	Debug::Log(transform_.rotate_.y, true);
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

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		//camState_ = (++camState_) % (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX)
			camState_ = CAM_TYPE::FIXED_TYPE;
		switch (camState_)
		{
		case CAM_TYPE::FIXED_TYPE:
			Camera::SetPosition(XMFLOAT3(0, 20, -20));
			Camera::SetTarget(XMFLOAT3(0, 0, 0));
			break;
		case CAM_TYPE::TPS_NO_ROT_TYPE:
			XMFLOAT3 campos = transform_.position_;
			transform_.position_.y = transform_.position_.y + 5.0f;
			transform_.position_.z = transform_.position_.z - 10.0f;
			Camera::SetPosition(campos);
			Camera::SetTarget(transform_.position_);
			break;

		
		case CAM_TYPE::TPS_TYPE:
			Camera::SetPosition(XMFLOAT3(0, 20, -30));
			Camera::SetTarget(XMFLOAT3(0, 0, 0));
			break;

		case CAM_TYPE::FPS_TYPE:
			break;
		default:
			break;
		}
	
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
