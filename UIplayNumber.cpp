#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"
#include<string>

using std::string;

UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), hPict_(-1)//, hPict_2(-1)
{
	//frame_ = {}
}

UIplayNumber::~UIplayNumber()
{
}

void UIplayNumber::Initialize()
{
	hPict_ = Image::Load("Model\\UI2_1_.png");
	assert(hPict_ >= 0);
	tensPlace_ = 3;
	onePlace_ = 0;
	/*hPict_2 = Image::Load("Model\\UI2_1_.png");
	assert(hPict_2 >= 0);*/
}

void UIplayNumber::Update()
{
	uiNum.position_ = { -0.32,0.85,0 };//•\Ž¦êŠ
	//uiNum_2.position_ = { -0.4,0.85,0 };



}

void UIplayNumber::Draw()
{
	
	pScene_ = (PlayScene*)GetParent();
	Transform trans;
	//trans.scale_ = { 1,1,1 };
	trans.position_ = { -0.32,0.85,0 };
	
	Image::SetRect(hPict_, frameWidth_* onePlace_, 0, frameWidth_, frameHeight_);
	Image::SetTransform(hPict_, trans);
	Image::Draw(hPict_);

	trans.position_ = { -0.4,0.85,0 };
	
	Image::SetRect(hPict_, frameWidth_* tensPlace_, 0, frameWidth_, frameHeight_);
	Image::SetTransform(hPict_, trans);
	Image::Draw(hPict_);
	
	

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
  		/*if (tensPlace_ == 3 && onePlace_ == 0) {
			tensPlace_ = 2;
		}
		else if (tensPlace_ == 2 && onePlace_ == 0) {
			tensPlace_ = 1;
		}
		else if (tensPlace_ == 1 && onePlace_ == 0) {
			tensPlace_ = 0;
		}
		else{
		}

		if (onePlace_ == 0) {
			onePlace_ = 9;
		}
		else {
			onePlace_  -= 1;
		}*/
	}
	
}

void UIplayNumber::Release()
{
}
