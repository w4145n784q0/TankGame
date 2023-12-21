#include "PlayScene.h"
#include"Engine/Model.h"
#include"Ground.h"
#include"Tank.h"

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
