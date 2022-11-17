#include "Play.h"
#include"Player.h"
#include "Result.h"

//@brief PlayScene�R���X�g���N�^�[//

Play::Play()
    :SceneBase()
    , cPos(VGet(0.0f, 45.0f, -50.0f))
    , cTarget(VGet(0.0f, 0.0f, 0.0f))
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Play.png");

    SetCameraNearFar(cNear, cFar);      //���s��0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
    SetCameraPositionAndTarget_UpVecY(cPos, cTarget);   //���_����^�[�Q�b�g������p�x�ɃJ�����ݒu

    player = new Player();
}

//@brief PlayScene�f�X�g���N�^�[//

Play::~Play()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

//@biref PlayScene�X�V����//

SceneBase* Play::Update(float deltaTime)
{
    player->Update();
    if (CheckHitKey(KEY_INPUT_R))
    {
        return new Result();
    }
    return this;
}

//@brief PlayScene�`�揈��//

void Play::Draw()
{

    DrawGraph(BgX, BgY, BgHandle, TRUE);
    player->Draw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Play���:R��Result�V�[���ֈڍs");
}