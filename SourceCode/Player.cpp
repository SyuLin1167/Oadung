#include "Player.h"
#include"ObjManager.h"
#include "Archer.h"

// @brief Player�R���X�g���N�^�[ //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
{
    objHandle = MV1LoadModel("SourceCode/Assets/Player/PlayerModel.mv1");     //���f���ǂݍ���
    MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));							//���f���̃T�C�Y�ݒ�
    objDir = VGet(0.0f, 0.0f, 1.0f);        //��������
    objSpeed = 5.0f;                        //�������x

    //---�����蔻�苅�ݒ�---//
    colSphere.localCenter = VGet(0, 10, 0);			//���[�J�����W
    colSphere.Radius = 5.0f;						//�����a
    colSphere.worldCenter = objPos;					//���[���h���W
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
        objPos += InputVec * objSpeed * deltaTime;                  //�ړ�
    }
    
    MV1SetPosition(objHandle, objPos);                              //�|�W�V�����ݒ�

    MATRIX RotMatY = MGetRotY(180.0f * (float)(DX_PI / 180.0f));       //�t�����Ȃ̂�180�x��]
    VECTOR negativeVec = VTransform(objDir, RotMatY);
    MV1SetRotationZYAxis(objHandle, negativeVec,
        VGet(0.0f, 1.0f, 0.0f), 0.0f);         //���f����]

    colSphere.Move(objPos);					//�����蔻��̈ړ�

    putTime -= deltaTime;
    if (putTime < 0.0f && GetMouseInput() & MOUSE_INPUT_LEFT)          //���N���b�N������
    {

        archer = new Archer(this);     //�V�K�쐬
        ObjManager::Entry(archer);
        putTime = putInterval;
    }
    if (archer != nullptr)
    {
        //---�����蔻�苅�擾---//
        Sphere sArc, sPly;
        sArc = archer->GetColSphere();
        sPly = this->GetColSphere();

        if (CollisionPair(sArc, sPly))
        {
            archer->SetAlive(false);
        }
    }
}

// @brief Player�`�揈�� //

void Player::Draw()
{
    MV1DrawModel(objHandle);        //���f���`��

        //---�����蔻��f�o�b�O�`��(��ŏ���)---//
    DrawSphere3D(colSphere.worldCenter, colSphere.Radius, 8, GetColor(0, 255, 255), 0, FALSE);
}