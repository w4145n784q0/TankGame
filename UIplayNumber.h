#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;

const float frameWidth_ = 64.0;
const float frameHeight_ = 118.0;
const int frameMax{ 9 };

class UIplayNumber :
    public GameObject
{
    int hmodel_;
    Transform uiNum;
    vector<vector<float>> frame_;
    //vector<float> frame_;
    
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    UIplayNumber(GameObject* parent);

    //デストラクタ
    ~UIplayNumber();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

