#pragma once
#include "Engine/GameObject.h"

class Text;
class Tank;

//�c�@���������o�ϐ���4���
//��ʂɕ\��
//�G�̕����z�u



class PlayScene :
    public GameObject
{
    Text* pText;
    Tank* player;
    int enemyNum;
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
       
    PlayScene(GameObject * parent);

    //�f�X�g���N�^
       ~PlayScene();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
    //�C�����C����`
    void DescEnemy() { enemyNum--; }
    bool IsEnemyLeft() { return enemyNum > 0; }
    int GetEnemyNum() { return enemyNum; }
};

