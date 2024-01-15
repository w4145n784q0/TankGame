#include "Enemy.h"
#include "Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\kinoko2nd_animation.fbx");
	assert(hModel_ >= 0);
	
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0),0.5f);
	AddCollider(collision);
	/*
	//アニメーションのフレーム数をセット
	//引数：handle		設定したいモデルの番号
	//引数：startFrame	開始フレーム
	//引数：endFrame	終了フレーム
	//引数：animSpeed	アニメーション速度
	*/
	Model::SetAnimFrame(hModel_, 0, 60, 1);//アニメーションのセット
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
