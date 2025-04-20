#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int hModel_;//�^���N�̖C�����f��
    //���f�����̂̓O���[�o���̈�ɕۑ�����Ă���
public:
    // �R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="parent">�e�̃I�u�W�F�N�g�̃|�C���^</param>
    TankHead(GameObject* parent);

    //�f�X�g���N�^
    ~TankHead();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    /// <summary>
    /// ���f���ԍ���Ԃ��֐�
    /// </summary>
    /// <returns>���f���ԍ�</returns>
    int GetModelHandle() { return hModel_; }
};

