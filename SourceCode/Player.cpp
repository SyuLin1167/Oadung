#include "Player.h"


//@brief Player�R���X�g���N�^�[//

Player::Player()
    :PlyHandle(-1)
    , PlayerPos(VGet(0.0f, 0.0f, 0.0f))
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
    MV1SetPosition(PlyHandle, PlayerPos);       //�|�W�V�����ݒ�

    //�ړ�����//
    if (CheckHitKey(KEY_INPUT_LEFT))            //���ړ�
    {
        if (PlayerPos.x > -10)                       //��ʊO�łȂ����
        {
            PlayerPos.x -= FirstSpeed;              //�ړ�
        }
    }
    else if (CheckHitKey(KEY_INPUT_RIGHT))      //�E�ړ�
    {
        if (PlayerPos.x < 10)
        {
            PlayerPos.x += FirstSpeed;
        }
    }
    else if (CheckHitKey(KEY_INPUT_UP))         //��ړ�
    {
        PlayerPos.z += FirstSpeed;
    }
    else if (CheckHitKey(KEY_INPUT_DOWN))       //���ړ�
    {
        PlayerPos.z -= FirstSpeed;
    }

}

//@brief Player�`�揈��

void Player::Draw()
{
    MV1DrawModel(PlyHandle);
}