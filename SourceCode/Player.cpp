#include "Player.h"

#include "Archer.h"

// @brief Player�R���X�g���N�^�[ //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
    ,animType(IDLE)
{
    //---���f���ǂݍ���---//
    objHandle =AssetManager::GetMesh("SourceCode/Assets/Player/PlayerModel.mv1");       //���f���ǂݍ���
    MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));                                     //���f���̃T�C�Y�ݒ�

    plyAnim = new Animation(objHandle);                                                 //�A�j���[�V�����̃C���X�^���X

    //---�A�j���[�V�����ǂݍ���---//
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Idle.mv1");             //�ҋ@:0
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Run.mv1");              //����:1
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Atack.mv1",false);            //�U��:2

    //---�A�j���[�V������ԃZ�b�g---//
    animType = IDLE;
    plyAnim->StartAnim(IDLE);

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
    delete plyAnim;                         //�A�j���[�V�������
}

//@brief Player�X�V����//

void Player::Update(float deltaTime)
{
    plyAnim->AddAnimTime(deltaTime);            //���݂̃A�j���[�V�����Đ���i�߂�

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

        if (animType != RUN)
        {
            animType = RUN;
            plyAnim->StartAnim(RUN);
        }
    }
    else
    {
        if (animType != IDLE)
        {
            animType = IDLE;
            plyAnim->StartAnim(IDLE);
        }
    }

    MV1SetPosition(objHandle, objPos);                              //�|�W�V�����ݒ�

    MATRIX RotMatY = MGetRotY(180.0f * (float)(DX_PI / 180.0f));       //�t�����Ȃ̂�180�x��]
    VECTOR negativeVec = VTransform(objDir, RotMatY);
    MV1SetRotationZYAxis(objHandle, negativeVec,
        VGet(0.0f, 1.0f, 0.0f), 0.0f);         //���f����]

    colSphere.Move(objPos);					//�����蔻��̈ړ�

    putTime -= deltaTime;
    if (putTime < 0.0f && GetMouseInput() & MOUSE_INPUT_LEFT)           //���N���b�N������
    {

        archer = new Archer(this);                                      //�V�K�쐬
        ObjManager::Entry(archer);                                  //�z��ɒǉ�
        putTime = putInterval;
    }
    if (archer != nullptr)                                              //�C���X�^���X�̒��g����łȂ����
    {
        //---�����蔻�苅�擾---//
        Sphere sArc, sPly;
        sArc = archer->GetColSphere();                                  //�A�[�`���[�̓����蔻�苅�擾
        sPly = this->GetColSphere();                                    //�v���C���[�̓����蔻�苅�擾

        if (CollisionPair(sArc, sPly))                      //���̓��m�̓����蔻��
        {
            archer->SetAlive(false);                                //�������Ă����玀�S
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