#include "ClearScene.h"
#include"Engine/Model.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hmodel_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	hmodel_ = Image::Load("Model\\Tank_Win.png");
	assert(hmodel_ >= 0);

}

void ClearScene::Update()
{
	//マウスカーソルの位置
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();

	if (Input::IsKey(DIK_SPACE))//スペースキーを押したらもう一回プレイ
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	if (Input::IsKey(DIK_ESCAPE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	
	
}

void ClearScene::Draw()
{
	Image::SetTransform(hmodel_, transform_);
	Image::Draw(hmodel_);
}

void ClearScene::Release()
{
}
