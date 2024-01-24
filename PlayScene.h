#pragma once
#include "Engine/GameObject.h"

class Text;
class Tank;

//残機数をメンバ変数で4作る
//画面に表示
//敵の複数配置



class PlayScene :
    public GameObject
{
    Text* pText;
    Tank* player;
    int enemyNum;
public:
    // コンストラクタ
        //引数：parent  親オブジェクト（SceneManager）
       
    PlayScene(GameObject * parent);

    //デストラクタ
       ~PlayScene();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
    //インライン定義
    void DescEnemy() { enemyNum--; }
    bool IsEnemyLeft() { return enemyNum > 0; }
    int GetEnemyNum() { return enemyNum; }
};

