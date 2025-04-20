#include "ClearScene.h"
#include"Engine/Model.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hImage_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	hImage_ = Image::Load("Model\\Tank_Win.png");
	assert(hImage_ >= 0);

}

void ClearScene::Update()
{
	//�}�E�X�J�[�\���̈ʒu
	//XMFLOAT3 mouse;
	//mouse = Input::GetMousePosition();

	if (Input::IsKey(DIK_SPACE))//�X�y�[�X�L�[����������������v���C
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
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void ClearScene::Release()
{
}
