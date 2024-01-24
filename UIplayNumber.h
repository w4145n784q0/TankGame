#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;

const float frameWidth_ = 51.2;
const float frameHeight_ = 118.0;
const int frameMax{ 9 };

class UIplayNumber :
    public GameObject
{
    int hPict_;
    int hPict_2;
    Transform uiNum;
    Transform uiNum_2;
    //vector<vector<float>> frame_;
    vector<Transform> frame_;//数字用
    
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

