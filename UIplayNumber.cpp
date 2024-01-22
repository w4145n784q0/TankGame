#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"



UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), hmodel_(-1)
{
}

UIplayNumber::~UIplayNumber()
{
}

void UIplayNumber::Initialize()
{
	hmodel_ = Image::Load("Model\\UI2_.png");
	assert(hmodel_ >= 0);
}

void UIplayNumber::Update()
{
	uiNum.position_ = { 0.4,0.85,0 };
}

void UIplayNumber::Draw()
{
	Image::SetTransform(hmodel_, uiNum);
	Image::Draw(hmodel_);
}

void UIplayNumber::Release()
{
}
