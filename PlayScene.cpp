#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
#include"Engine/Camera.h"
#include"Engine/Text.h"
#include"Engine/GameObject.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	Instantiate<Enemy>(this);
	pText = new  Text;
	pText->Initialize();
	
}

void PlayScene::Update()
{
	Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "hello");
}


void PlayScene::Release()
{
	
}
