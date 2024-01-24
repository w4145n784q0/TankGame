#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"
#include<vector>
using std::vector;

const float frameWidth_ = 51.2;
const float frameHeight_ = 118.0;
const int frameMax{ 9 };

class UIplayNumber :
    public GameObject
{
    int Number_;
    int EnemyDisplay_;
    Transform ui;
    Transform uiNum;//��̈�
    Transform uiNum_2;//�\�̈�
    vector<Transform> frame_;//�����p
    PlayScene* pScene_;
    int onePlace_;//��̈�
    int tensPlace_;//�\�̈�
    
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    UIplayNumber(GameObject* parent);

    //�f�X�g���N�^
    ~UIplayNumber();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
   

};

