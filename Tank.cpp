#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
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
}

void Tank::Update()
{
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
		this->transform_.position_.z += 0.3;
	}
	if (Input::IsKey(DIK_S))
	{
		this->transform_.position_.z -= 0.3;
	}
	//Debug::Log("angle=");
}

void Tank::Draw()
{
	Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);
}

void Tank::Release()
{
}
