#include "Bullet.h"
#include"Engine/Model.h"
//#include "Engine/SphereCollider.h"
#include "Engine/SphereCollider.h"


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
	/*SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.3f);
	AddCollider(collision);*/
	

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
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

	//this->moveDir_.y = this->moveDir_.y - 0.01;//yç¿ïWÇóéÇ∆Ç∑
	moveDir_ = {moveDir_.x, moveDir_.y - 0.01f, moveDir_.z };

	if (transform_.position_.y < -20){
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

