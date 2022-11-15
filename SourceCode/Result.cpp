#include "Result.h"
#include"DxLib.h"
#include "Title.h"

//@brief ResultScene�R���X�g���N�^�[//

Result::Result()
    :SceneBase()
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Result.png");
}

//@brief ResultScene�f�X�g���N�^�[//

Result::~Result()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

//@brief ResultScene�X�V����//

SceneBase* Result::Update(float deltaTime)
{
    if (CheckHitKey(KEY_INPUT_T))
    {
        return new Title();
    }
    return this;
}

//@brief ResultScene�`�揈��//

void Result::Draw()
{
    DrawGraph(BgX, BgY, BgHandle, TRUE);
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Result���:T��Title�V�[���ֈڍs");
}