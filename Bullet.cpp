#include "Bullet.h"
#include"Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	//transform_.position_.z += 0.1;
	transform_.position_.x = transform_.position_.x + moveDir_.x * BulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * BulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * BulletSpeed_;

}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
