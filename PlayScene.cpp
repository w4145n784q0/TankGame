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
#include"UIplayNumber.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),isChange(false),enemyNum(0)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	

	enemyNum = ENEMY_NUM;
	for (int i = 0; i < ENEMY_NUM; i++) {
		Instantiate<Enemy>(this);
	}

	pText = new  Text;
	pText->Initialize();
	
	Instantiate<UIplayNumber>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{

}


void PlayScene::Release()
{
	
}


bool PlayScene::IsChangeNumber()
{
	if (isChange) {
		return true;
	}

	return false;
}


