#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
    int hmodel_;
    XMVECTOR front_;//前ベクトル　z方向大きさ1
    float speed_;
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

    //何かに当たった
  //引数：pTarget 当たった相手
   void OnCollision(GameObject* pTarget) override;
};

