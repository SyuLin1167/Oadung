#include "Player.h"


//@brief Player�R���X�g���N�^�[//

Player::Player()
    :PlyHandle(-1)
    , PlyPos(VGet(0.0f, 0.0f, 0.0f))
    ,PlyDir(VGet(0.0f,0.0f,1.0f))
    ,InputVec(VGet(0,0,0))
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

void Player::Update(float deltaTime)
{
    //�L�[���͔��菈��//
    KeyInput = false;                           //�����͎��͓��͔����FALSE��
    
    if (CheckHitKey(KEY_INPUT_LEFT))            //���L�[����
    {
        InputVec = VAdd(InputVec, LEFT);        //�x�N�g�����Z
        KeyInput = true;                        //���͔����TRUE��
    }
    if (CheckHitKey(KEY_INPUT_RIGHT))           //�E�L�[����
    {
        InputVec = VAdd(InputVec, RIGHT);
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_UP))              //��L�[����
    {
        InputVec = VAdd(InputVec, UP);
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_DOWN))            //���L�[����
    {
        InputVec = VAdd(InputVec, DOWN);
        KeyInput = true;
    }


    //�ړ�����//
    if (KeyInput)
    {
        InputVec = VNorm(InputVec);             //�x�N�g���̕����������擾
        PlyDir = InputVec;                      //�L�����̌���
        PlyPos = VAdd(PlyPos, VScale(InputVec, FirstSpeed * deltaTime));    //�ړ�
    }
    
    MV1SetPosition(PlyHandle, PlyPos);          //�|�W�V�����ݒ�

    MATRIX RotMatY = MGetRotY(180 - (DX_PI / 180.0f));                      //�t�����Ȃ̂�180�x��]


}

//@brief Player�`�揈��

void Player::Draw()
{
    MV1DrawModel(PlyHandle);
}