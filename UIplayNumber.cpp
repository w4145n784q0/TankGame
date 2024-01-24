#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"
#include<string>

using std::string;

UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), hPict_(-1), hPict_2(-1)
{
	//frame_ = {}
}

UIplayNumber::~UIplayNumber()
{
}

void UIplayNumber::Initialize()
{
	hPict_ = Image::Load("Model\\UI2_1_.png");
	hPict_2 = Image::Load("Model\\UI2_1_.png");
	assert(hPict_ >= 0);
	assert(hPict_2 >= 0);
}

void UIplayNumber::Update()
{
	uiNum.position_ = { -0.3,0.85,0 };//ï\é¶èÍèä
	uiNum_2.position_ = { -0.4,0.85,0 };
}

void UIplayNumber::Draw()
{

	Image::SetTransform(hPict_, uiNum);
	Image::SetRect(hPict_, 0, 0, frameWidth_, frameHeight_);
	Image::Draw(hPict_);
	Image::SetTransform(hPict_2, uiNum_2);
	Image::SetRect(hPict_2, frameWidth_*3, 0, frameWidth_, frameHeight_);
	Image::Draw(hPict_2);

	//string uistr = 
	
}

void UIplayNumber::Release()
{
}
