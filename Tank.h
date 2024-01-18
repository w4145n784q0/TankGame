#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
    int hmodel_;
    XMVECTOR front_;//�O�x�N�g���@z�����傫��1
    float speed_;//0.05 0.05*60 m/s
    int camState_;
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Tank(GameObject* parent);

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

