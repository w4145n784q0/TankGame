#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
    int hmodel_;//ステージモデル
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
    Ground(GameObject* parent);

    //デストラクタ
    ~Ground();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //モデル番号のゲット関数
    int GetModelHandle() { return(hmodel_); }
};
