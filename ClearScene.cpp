#include "ClearScene.h"
#include"Engine/Model.h"
#include"Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hmodel_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	hmodel_ = Image::Load("Model\\TankWin.png");
	assert(hmodel_ >= 0);

}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Image::SetTransform(hmodel_, transform_);
	Image::Draw(hmodel_);
}

void ClearScene::Release()
{
}
