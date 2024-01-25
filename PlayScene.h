#pragma once
#include "Engine/GameObject.h"

class Text;
class Tank;

class PlayScene :
    public GameObject
{
    Text* pText;
    Tank* player;
    int enemyNum;
    bool isChange;
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

    //敵の数を下げる
    void DescEnemy() { enemyNum--; }
   //敵が0体より多いか
    bool IsEnemyLeft() { return enemyNum > 0; }
    //敵数のゲット関数
    int GetEnemyNum() { return enemyNum; }
    //敵が倒されたときuiのカウントを下げるときに使う
    void ChangeNumberTrue() { isChange = true; }
    //カウントを下げたらfalseにして状態リセット
    void ChangeNumberFalse() { isChange = false; }
    //カウントを下げてもいいか返す
    bool IsChangeNumber();
};

