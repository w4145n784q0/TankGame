#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
    int hmodel_;//�X�e�[�W���f��
public:
    // �R���X�g���N�^
        //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Ground(GameObject* parent);

    //�f�X�g���N�^
    ~Ground();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //���f���ԍ��̃Q�b�g�֐�
    int GetModelHandle() { return(hmodel_); }
};
