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
	const float ColliderSize = 1.2f;//当たり判定のサイズ
	const float tankSpeed = 0.05f;//タンクの速度
	const double enemyKillSpeed = 0.005;//敵に接触した際に加算するスピード
	const XMFLOAT3 FixedCamera = { 0, 20, -20 };//固定カメラ位置
	const XMFLOAT3 FixedTarget = { 0,0,0 };//固定カメラの焦点
	const XMFLOAT3 camposPlus = { 0,15,-10 };//TPS_NO_ROTに加算
	const XMVECTOR vectorEye = { 0, 5, -10, 0 };//TPS視点
}

//カメラ制御
enum CAM_TYPE
{
	FIXED_TYPE,//固定
	TPS_NO_ROT_TYPE,//三人称回転なし
	TPS_TYPE,//三人称
	FPS_TYPE,//一人称
	MAX//番兵（チェック用の値）
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
	Instantiate<TankHead>(this);//タンクcppにタンクヘッドを初期化
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), ColliderSize);
	AddCollider(collision);
}

void Tank::Update()
{

	XMMATRIX rotY = XMMatrixIdentity();//行列　//XMMatrixIdentityは何もしない行列
	XMVECTOR move{0,0,0,0};//xyz全部0
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

	//回転行列を求める
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//y軸に自機の回転した分だけ回転させる行列
	//ベクトルの回転結果を求める
	rotVec = XMVector3TransformCoord(front_, rotY);//（ベクトルfrontを行列rotYで変形）
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//自機の場所


	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);//XMStoreFloat3(行列,ベクトル)



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

	if (Input::IsKeyDown(DIK_Z))//タンクの視点変更
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
		speed_ += enemyKillSpeed;//Enemyとぶつかるとスピードアップ
	}
}
