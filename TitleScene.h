#pragma once
#include "Engine/GameObject.h"
class TitleScene :
    public GameObject
{
    int hmodel_;
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    TitleScene(GameObject* parent);

    //�f�X�g���N�^
    ~TitleScene();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

