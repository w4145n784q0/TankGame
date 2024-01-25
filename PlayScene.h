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

    //�G�̐���������
    void DescEnemy() { enemyNum--; }
   //�G��0�̂�葽����
    bool IsEnemyLeft() { return enemyNum > 0; }
    //�G���̃Q�b�g�֐�
    int GetEnemyNum() { return enemyNum; }
    //�G���|���ꂽ�Ƃ�ui�̃J�E���g��������Ƃ��Ɏg��
    void ChangeNumberTrue() { isChange = true; }
    //�J�E���g����������false�ɂ��ď�ԃ��Z�b�g
    void ChangeNumberFalse() { isChange = false; }
    //�J�E���g�������Ă��������Ԃ�
    bool IsChangeNumber();
};

