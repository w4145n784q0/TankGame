#pragma once
#include "Engine/GameObject.h"
#include"PlayScene.h"
class Enemy :
    public GameObject
{
private:
    int hModel_; //�G���f��
    PlayScene* pScene_;
public:
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
    
};

