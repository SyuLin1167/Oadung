#include "Play.h"
#include"Player.h"
#include"Sniper.h"
#include "Result.h"

// @brief PlayScene�R���X�g���N�^�[ //

Play::Play()
    :SceneBase()
    , cPos(VGet(0.0f, 40.0f, -70.0f))
    , cTarget(VGet(0.0f, 0.0f, 0.0f))
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Play.png");

    SetCameraNearFar(cNear, cFar);                      //�J�����̕`��͈͐ݒ�
    SetCameraPositionAndTarget_UpVecY(cPos, cTarget);   //���_����^�[�Q�b�g������p�x�ɃJ�����ݒu

    player = new Player();
}

// @brief PlayScene�f�X�g���N�^�[ //

Play::~Play()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

// @biref PlayScene�X�V���� //

SceneBase* Play::Update(float deltaTime)
{
    player->Update(deltaTime);

    putTime -= deltaTime;
    if (putTime < 0.0f&&GetMouseInput()&MOUSE_INPUT_LEFT)          //�G���^�[�L�[�������ꂽ��
    {
        for (int i = 0; i < 5; i++)             //�|�C���^�̋󂫂�����
        {
            if (snpArray[i] == nullptr)         //�󂫂���������
            {
                snpArray[i] = new Sniper();     //�V�K�쐬
                putTime = putInterval;
                break;                          //for���𔲂���
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (snpArray[i] != nullptr)
        {
            snpArray[i]->Update(deltaTime);
            if (snpArray[i]->IsDead())
            {
                delete snpArray[i];
                snpArray[i] = nullptr;
            }
        }
    }

    if (CheckHitKey(KEY_INPUT_R))
    {
        return new Result();
    }
    return this;
}

// @brief PlayScene�`�揈�� //

void Play::Draw()
{
    //---�n�ʃO���b�h��`��---//(�̂��ɃQ�[���I�u�W�F�N�g�Ɉڍs)
    for (int ix = 0; ix < divideNum+1; ix++)
    {
        p1 = VGet(ix * gridSpace - gridAllSize * 0.5f, 0.0f, -gridAllSize * 0.5f);
        p2 = VGet(ix * gridSpace - gridAllSize * 0.5f, 0.0f, gridAllSize * 0.5f);

        DrawLine3D(p1, p2, GetColor(0, 255, 0));
    }
    for (int iy = 0; iy < divideNum + 1; iy++)
    {
        p1 = VGet(-gridAllSize * 0.5f, 0.0f, iy * gridSpace - gridAllSize * 0.5f);
        p2 = VGet(gridAllSize * 0.5f, 0.0f, iy * gridSpace - gridAllSize * 0.5f);

        DrawLine3D(p1, p2, GetColor(0, 255, 0));
    }//�`��I���

    //DrawGraph(BgX, BgY, BgHandle, TRUE);
    player->Draw();

    for (int i = 0; i < 5; i++)
    {
        if (snpArray[i] != nullptr)
        {
            snpArray[i]->Draw();
        }
    }
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Play���:R��Result�V�[���ֈڍs");
}