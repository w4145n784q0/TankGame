#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"
#include<string>

using std::string;

namespace
{
	const XMFLOAT3 Hud = { -0.6,0.85,0 };//•\Ž¦êŠ
	const XMFLOAT3 One = { -0.32,0.85,0 };
	const XMFLOAT3 Two = { -0.4,0.85,0 };
	const XMFLOAT3 HowPlay = { -0.6,-0.65,0 };
}

UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), Number_(-1), EnemyDisplay_(-1),Howplay_(-1)
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
	Howplay_ = Image::Load("Model\\UI3_.png");
	assert(Howplay_ >= 0);
	tensPlace_ = 3;
	onePlace_ = 0;
}

void UIplayNumber::Update()
{
	pScene_ = (PlayScene*)GetParent();
	ui.position_ = Hud;//•\Ž¦êŠ
	uiNum.position_ = One;
	uiNum_2.position_ = Two;
	ui_howplay.position_ = HowPlay;

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

	Image::SetTransform(Howplay_, ui_howplay);
	Image::Draw(Howplay_);
}

void UIplayNumber::Release()
{
}
