#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"

const float frameWidth_ = 51.2;
const float frameHeight_ = 118.0;
const int frameMax{ 9 };

class UIplayNumber :
    public GameObject
{
    int Number_;//数字表示
    int EnemyDisplay_;//「残りの数～」表示
    int Howplay_;//操作方法
    Transform ui;//HUDの表示
    Transform uiNum;//一の位
    Transform uiNum_2;//十の位
    Transform ui_howplay;//十の位
    PlayScene* pScene_;
    int onePlace_;//一の位
    int tensPlace_;//十の位
    
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

