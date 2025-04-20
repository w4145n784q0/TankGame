#include "Enemy.h"
#include "Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"Ground.h"
#include"PlayScene.h"

namespace
{
	const float ColliderSize = 0.5f;//当たり判定のサイズ
	const float distPlus = 0.5f;//敵の高さの調整
	const float MaxEnemyInit = 25.0f;//敵の出現位置の最大
	const int startFrame = 0;//アニメフレームの開始
	const int endFrame = 60;//アニメフレームの終了
}

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
	//pScene_ = (PlayScene*)GetParent();
	
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), ColliderSize);
	AddCollider(collision);

	/*
	//アニメーションのフレーム数をセット
	//引数：handle		設定したいモデルの番号
	//引数：startFrame	開始フレーム
	//引数：endFrame	終了フレーム
	//引数：animSpeed	アニメーション速度
	*/
	Model::SetAnimFrame(hModel_, startFrame, endFrame, 1);//アニメーションのセット
	float x = (float)rand() / RAND_MAX;//0-1の乱数
	x = 2.0 * x;//0-5の乱数
	transform_.position_.x = MaxEnemyInit * (x - 1.0);//25.0 * (x - 1.0)の乱数

	float z = (float)rand() / RAND_MAX;//0-1の乱数
	z = 2.0 * z;//0-5の乱数
	transform_.position_.z = MaxEnemyInit * (z - 1.0);//25.0 * (x - 1.0)の乱数
	transform_.position_.y = 0;

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);
	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + distPlus;
	}


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
		pScene_ = (PlayScene*)GetParent();
		pScene_->DescEnemy();
		this->KillMe();
		pTarget->KillMe();
		pScene_->ChangeNumberTrue();
	}
	if (pTarget->GetObjectName() == "Tank") {
		pScene_ = (PlayScene*)GetParent();
		pScene_->DescEnemy();
		this->KillMe();
		pScene_->ChangeNumberTrue();
	}
}
