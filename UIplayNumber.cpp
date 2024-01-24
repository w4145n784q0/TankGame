#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"
#include<string>

using std::string;

UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), Number_(-1), EnemyDisplay_(-1)
{
	
}

UIplayNumber::~UIplayNumber()
{
}

void UIplayNumber::Initialize()
{
	Number_ = Image::Load("Model\\UI2_1_.png");
	assert(Number_ >= 0);
	EnemyDisplay_ = Image::Load("Model\\UI1_.png");
	assert(EnemyDisplay_ >= 0);

	tensPlace_ = 3;
	onePlace_ = 0;
	/*hPict_2 = Image::Load("Model\\UI2_1_.png");
	assert(hPict_2 >= 0);*/
}

void UIplayNumber::Update()
{
	pScene_ = (PlayScene*)GetParent();
	//Transform trans;
	ui.position_ = { -0.6,0.85,0 };
	uiNum.position_ = { -0.32,0.85,0 };//•\Ž¦êŠ
	uiNum_2.position_ = { -0.4,0.85,0 };

	if (pScene_->IsChangeNumber())
	{
		if (tensPlace_ == 3 && onePlace_ == 0) {
			tensPlace_ = 2;
		}
		else if (tensPlace_ == 2 && onePlace_ == 0) {
			tensPlace_ = 1;
		}
		else if (tensPlace_ == 1 && onePlace_ == 0) {
			tensPlace_ = 0;
		}

		if (onePlace_ == 0) {
			onePlace_ = 9;
		}
		else {
			onePlace_ -= 1;
		}
		pScene_->ChangeNumberFalse();
	}
}

void UIplayNumber::Draw()
{
	Image::SetTransform(EnemyDisplay_, ui);
	Image::Draw(EnemyDisplay_);

	Image::SetRect(Number_, frameWidth_* onePlace_, 0, frameWidth_, frameHeight_);
	Image::SetTransform(Number_, uiNum);
	Image::Draw(Number_);
	
	Image::SetRect(Number_, frameWidth_* tensPlace_, 0, frameWidth_, frameHeight_);
	Image::SetTransform(Number_, uiNum_2);
	Image::Draw(Number_);
}

void UIplayNumber::Release()
{
}
