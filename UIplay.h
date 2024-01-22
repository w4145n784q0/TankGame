#pragma once
#include "Engine/GameObject.h"
class UIplay :
    public GameObject
{
    int hmodel_;
    Transform ui;
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    UIplay(GameObject* parent);

    //デストラクタ
    ~UIplay();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

