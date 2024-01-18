#include "ClearScene.h"
#include"Engine/Model.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hmodel_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	//hmodel_ = Model::Load("clear.png");
	assert(hmodel_ >= 0);

}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);
}

void ClearScene::Release()
{
}
