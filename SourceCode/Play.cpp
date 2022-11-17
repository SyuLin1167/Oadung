#include "Play.h"
#include"Player.h"
#include "Result.h"

//@brief PlaySceneコンストラクター//

Play::Play()
    :SceneBase()
    , cPos(VGet(0.0f, 45.0f, -50.0f))
    , cTarget(VGet(0.0f, 0.0f, 0.0f))
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Play.png");

    SetCameraNearFar(cNear, cFar);      //奥行き0.1～1000までをカメラの描画範囲とする
    SetCameraPositionAndTarget_UpVecY(cPos, cTarget);   //視点からターゲットを見る角度にカメラ設置

    player = new Player();
}

//@brief PlaySceneデストラクター//

Play::~Play()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

//@biref PlayScene更新処理//

SceneBase* Play::Update(float deltaTime)
{
    player->Update();
    if (CheckHitKey(KEY_INPUT_R))
    {
        return new Result();
    }
    return this;
}

//@brief PlayScene描画処理//

void Play::Draw()
{

    DrawGraph(BgX, BgY, BgHandle, TRUE);
    player->Draw();
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Play画面:RでResultシーンへ移行");
}