#include "Player.h"

// @brief Player�R���X�g���N�^�[ //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
{
    objHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");     //���f���ǂݍ���
    objDir = VGet(0.0f, 0.0f, 1.0f);        //��������
    objSpeed = 5.0f;                        //�������x
}

// @brief Player�f�X�g���N�^�[ //

Player::~Player()
{
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
        objDir = InputVec;                                          //�L�����̌���
        objPos += InputVec * objSpeed * deltaTime;                //�ړ�
    }
    
    MV1SetPosition(objHandle, objPos);                              //�|�W�V�����ݒ�

    MATRIX RotMatY = MGetRotY(180 * (float)(DX_PI / 180.0f));       //�t�����Ȃ̂�180�x��]
    MV1SetRotationZYAxis(objHandle, VTransform(objDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //���f����]

}

// @brief Player�`�揈�� //

void Player::Draw()
{
    MV1DrawModel(objHandle);        //���f���`��
}