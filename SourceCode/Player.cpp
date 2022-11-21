#include "Player.h"
#include"Math.h"

// @brief Player�R���X�g���N�^�[ //

Player::Player()
    :plyHandle(-1)
    ,plyPos(VGet(0.0f, 0.0f, 0.0f))
    ,plyDir(VGet(0.0f,0.0f,1.0f))
    ,InputVec(VGet(0,0,0))
    ,KeyInput(false)
{
    plyHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");
}

// @brief Player�f�X�g���N�^�[ //

Player::~Player()
{
    if (plyHandle != -1)
    {
        MV1DeleteModel(plyHandle);
    }
}

//@brief Player�X�V����//

void Player::Update(float deltaTime)
{
    //---�L�[���͔��菈��---//
    KeyInput = false;                           //�����͎��͓��͔����FALSE��
    
    if (CheckHitKey(KEY_INPUT_LEFT))            //���L�[����
    {
        InputVec += LEFT;                       //�x�N�g�����Z
        KeyInput = true;                        //���͔����TRUE��
    }
    if (CheckHitKey(KEY_INPUT_RIGHT))           //�E�L�[����
    {
        InputVec += RIGHT;
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_UP))              //��L�[����
    {
        InputVec += UP;
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_DOWN))            //���L�[����
    {
        InputVec += DOWN;
        KeyInput = true;
    }


    //---�ړ�����---//
    if (KeyInput)
    {
        InputVec = VNorm(InputVec);                                 //�x�N�g���̕����������擾
        plyDir = InputVec;                                          //�L�����̌���
        plyPos += InputVec * FirstSpeed * deltaTime;                //�ړ�
    }
    
    MV1SetPosition(plyHandle, plyPos);                              //�|�W�V�����ݒ�

    MATRIX RotMatY = MGetRotY(180 * (float)(DX_PI / 180.0f));       //�t�����Ȃ̂�180�x��]
    MV1SetRotationZYAxis(plyHandle, VTransform(plyDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //���f����]

}

// @brief Player�`�揈�� //

void Player::Draw()
{
    MV1DrawModel(plyHandle);
}