#include "TitleScene.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Image.h"
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
	hmodel_ = Image::Load("Model\\KinokovsTank.png");
	assert(hmodel_ >= 0); 
}

void TitleScene::Update()
{
	
	if (Input::IsKey(DIK_SPACE))//スペースキーを押したらゲームスタート
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hmodel_, transform_);
	Image::Draw(hmodel_);
}

void TitleScene::Release()
{
}
