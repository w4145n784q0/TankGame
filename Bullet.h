#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"
class Bullet :
    public GameObject
{
private:
    int hModel_;//バレットのモデル番号
    float BulletSpeed_;
    XMFLOAT3 moveDir_;
    
public:
    // コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）


    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="parent">親のオブジェクトのポインタ</param>
    Bullet(GameObject* parent);

    //デストラクタ
    ~Bullet();

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
   

    void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
    void SetSpeed(float _speed) { BulletSpeed_ = _speed; }
};

