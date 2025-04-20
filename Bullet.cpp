#include "Bullet.h"
#include"Engine/Model.h"
#include "Engine/SphereCollider.h"

namespace
{
	const float ColliderSize = 1.2f;//当たり判定のサイズ
	const float DownSpeed = 0.01f;//毎フレーム高さが下がる値
	const int BulletKillLine = -20;//弾を消す高さ
}

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1),BulletSpeed_(0),moveDir_(0,0,0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), ColliderSize);
	AddCollider(collision);
	
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + moveDir_.x * BulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * BulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * BulletSpeed_;
	//transform.position => xmvector pos
	//movedir -> xmvector dir;
	//pos -> pos + bulletspeed * dir;

	moveDir_ = {moveDir_.x, moveDir_.y - DownSpeed, moveDir_.z };//y座標を落とす
	if (transform_.position_.y < BulletKillLine){
		this->KillMe();
	}

}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

