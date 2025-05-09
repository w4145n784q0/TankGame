#pragma once
#include "Engine/GameObject.h"
class ClearScene :
    public GameObject
{
    int hImage_;//タイトル画像ハンドル
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    ClearScene(GameObject* parent);

    //デストラクタ
    ~ClearScene();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

