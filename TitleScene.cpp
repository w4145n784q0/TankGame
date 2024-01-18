#include "TitleScene.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),hmodel_(-1)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	hmodel_ = Model::Load("KinokovsTank.png");
	assert(hmodel_ >= 0); 
}

void TitleScene::Update()
{
	
	if (Input::IsKey(DIK_SPACE))
	{
		/*SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);*/
	}
}

void TitleScene::Draw()
{
	/*Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);*/
}

void TitleScene::Release()
{
}
