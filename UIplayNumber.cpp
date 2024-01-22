#include "UIplayNumber.h"
#include"Engine/Image.h"
#include"Enemy.h"



UIplayNumber::UIplayNumber(GameObject* parent)
	:GameObject(parent, "UIplayNumber"), hmodel_(-1)
{
	frame_ = {
	{frameWidth_ * 0,frameHeight_} ,
	{frameWidth_ * 1,frameHeight_} ,
	{frameWidth_ * 2,frameHeight_} ,
	{frameWidth_ * 3,frameHeight_} ,
	{frameWidth_ * 4,frameHeight_} ,
	{frameWidth_ * 5,frameHeight_} ,
	{frameWidth_ * 6,frameHeight_} ,
	{frameWidth_ * 7,frameHeight_} ,
	{frameWidth_ * 8,frameHeight_} ,
	{frameWidth_ * 9,frameHeight_} ,
	
	};
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
