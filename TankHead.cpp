#include "TankHead.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Bullet.h"

namespace
{
	const float speed = 0.2f;
}

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if(Input::IsKey(DIK_LEFTARROW))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_RIGHTARROW))
	{
		this->transform_.rotate_.y += 1;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//XMFLOATは保存のための型(計算できない)　VECTOR型は計算に使う

		XMFLOAT3 CannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 CannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		
		XMVECTOR vtop = XMLoadFloat3(&CannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&CannonRootPos);
		XMVECTOR movedir = vtop - vroot;
		movedir = XMVector3Normalize(movedir);
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, movedir);
		
		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(CannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(speed);
	}
}

void TankHead::Draw()
{
	//transform_は自分(tankhead)のメンバ変数
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{

}
