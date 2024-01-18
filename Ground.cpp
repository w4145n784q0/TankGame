#include "Ground.h"
#include"Engine/Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"), hmodel_(-1)
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	hmodel_ = Model::Load("Model\\ground_.fbx");
	assert(hmodel_ >= 0);
	
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hmodel_, transform_);
	Model::Draw(hmodel_);
}

void Ground::Release()
{
}
