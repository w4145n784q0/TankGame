#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"
#include"TankHead.h"
#include"Enemy.h"
#include"Engine/Camera.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hmodel_(-1)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	

}

void PlayScene::Draw()
{

}


void PlayScene::Release()
{
}
