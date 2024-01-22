#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
#include"Engine/Camera.h"
#include"Engine/Text.h"
#include"Engine/GameObject.h"
#include"Engine/SceneManager.h"
#include"UIplay.h"
#include"UIplayNumber.h"



namespace
{
	const int ENEMY_NUM{ 30 };
}

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
	Instantiate<UIplay>(this);
	Instantiate<UIplayNumber>(this);

	enemyNum = ENEMY_NUM;
	for (int i = 0; i < ENEMY_NUM; i++) {
		Instantiate<Enemy>(this);
	}
	pText = new  Text;
	pText->Initialize();
	
}

void PlayScene::Update()
{
	
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "");
}


void PlayScene::Release()
{
	
}
