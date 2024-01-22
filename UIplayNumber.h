#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;

const float frameWidth_ = 64.0;
const float frameHeight_ = 118.0;
const int frameMax{ 9 };

class UIplayNumber :
    public GameObject
{
    int hmodel_;
    Transform uiNum;
    vector<vector<float>> frame_;
    //vector<float> frame_;
    
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

