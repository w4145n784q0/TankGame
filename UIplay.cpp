#include "UIplay.h"
#include"Engine/Image.h"



UIplay::UIplay(GameObject* parent)
	:GameObject(parent, "UIplay"), hmodel_(-1)
{
}

UIplay::~UIplay()
{
}

void UIplay::Initialize()
{
	hmodel_ = Image::Load("Model\\UI1_.png");
	assert(hmodel_ >= 0);
	
}

void UIplay::Update()
{
	ui.position_ = { -0.6,0.85,0 };
}

void UIplay::Draw()
{
	Image::SetTransform(hmodel_,ui);
	Image::Draw(hmodel_);
}

void UIplay::Release()
{
}
