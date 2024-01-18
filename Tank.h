#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
    int hmodel_;
    XMVECTOR front_;//前ベクトル　z方向大きさ1
    float speed_;//0.05 0.05*60 m/s
    int camState_;
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    Tank(GameObject* parent);

    //デストラクタ
    ~Tank();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

