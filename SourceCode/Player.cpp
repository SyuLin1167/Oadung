#include "Player.h"


//@brief Player�R���X�g���N�^�[//

Player::Player()
    :PlyHandle(-1)
    , PlyPos(VGet(0.0f, 0.0f, 0.0f))
    ,PlyDir(VGet(0.0f,0.0f,1.0f))
    ,KeyInput(false)
{
    PlyHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");
}

//@brief Player�f�X�g���N�^�[//

Player::~Player()
{
    if (PlyHandle != -1)
    {
        MV1DeleteModel(PlyHandle);
    }
}

//@brief Player�X�V����

void Player::Update()
{
    MV1SetPosition(PlyHandle, PlyPos);       //�|�W�V�����ݒ�

    //�ړ�����//
    if (CheckHitKey(KEY_INPUT_LEFT))            //���ړ�
    {
        if (PlyPos.x > -10)
        {
            PlyPos.x -= FirstSpeed;
        }
    }
    else if (CheckHitKey(KEY_INPUT_RIGHT))      //�E�ړ�
    {
        if (PlyPos.x < 10)
        {
            PlyPos.x += FirstSpeed;
        }
    }
    else if (CheckHitKey(KEY_INPUT_UP))         //��ړ�
    {
        PlyPos.z += FirstSpeed;
    }
    else if (CheckHitKey(KEY_INPUT_DOWN))       //���ړ�
    {
        PlyPos.z -= FirstSpeed;
    }

}

//@brief Player�`�揈��

void Player::Draw()
{
    MV1DrawModel(PlyHandle);
}