#pragma once
#include "Engine/GameObject.h"
class UIplayNumber :
    public GameObject
{
    int hmodel_;
    Transform uiNum;
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

