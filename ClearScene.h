#pragma once
#include "Engine/GameObject.h"
class ClearScene :
    public GameObject
{
    int hImage_;//�^�C�g���摜�n���h��
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    ClearScene(GameObject* parent);

    //�f�X�g���N�^
    ~ClearScene();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

