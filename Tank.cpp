#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Ground.h"

Tank::Tank(GameObject* parent)
	:GameObject( parent,"Tank"),hmodel_(-1)
{
}

Tank::~Tank()
{
	
}

void Tank::Initialize()
{
	hmodel_ = Model::Load("Model\\TankBody.fbx");
	assert(hmodel_ >= 0);
	front_ = { 0,0,1,0 };
	speed_ = 0.05;
}

void Tank::Update()
{
	//‰ñ“]s—ñ‚ð‹‚ß‚é
	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));;
	//ƒxƒNƒgƒ‹‚Ì‰ñ“]Œ‹‰Ê‚ð‹‚ß‚é
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
}

void Tank::Draw()
{
	Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);
	
}

void Tank::Release()
{
}
