#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
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
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "hello");
}


void PlayScene::Release()
{
	
}
