#pragma once
#include "Engine/GameObject.h"
class UIplayNumber :
    public GameObject
{
    int hmodel_;
    Transform uiNum;
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

