#include "Title.h"
#include "DxLib.h"
#include "Play.h"

// @brief TitleScene�R���X�g���N�^�[ //

Title::Title()
    :SceneBase()
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Title.png");
}

// @brief TitleScene�f�X�g���N�^�[ //

Title::~Title()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

// @brief TitleScene�X�V���� //

SceneBase* Title::Update(float deltaTime)
{
    if (CheckHitKey(KEY_INPUT_P))
    {
        return new Play();
    }
    return this;
}

// @brief TitleScene�`�揈�� //

void Title::Draw()
{
    DrawGraph(BgX, BgY, BgHandle, TRUE);
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Title���:P��Play�V�[���ֈڍs");
}