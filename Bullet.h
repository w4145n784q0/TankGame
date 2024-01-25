#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"
class Bullet :
    public GameObject
{
private:
    int hModel_;//�o���b�g�̃��f���ԍ�
    float BulletSpeed_;
    XMFLOAT3 moveDir_;//�e�̐i�s����
    
public:
    // �R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j


    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="parent">�e�̃I�u�W�F�N�g�̃|�C���^</param>
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

   
    //�i�s�����̃Z�b�g�֐�
    void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
    //�X�s�[�h�̃Z�b�g�֐�
    void SetSpeed(float _speed) { BulletSpeed_ = _speed; }
};

