#pragma once
#include "Engine/GameObject.h"
class UIplay :
    public GameObject
{
    int hmodel_;
    Transform ui;
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    UIplay(GameObject* parent);

    //�f�X�g���N�^
    ~UIplay();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

