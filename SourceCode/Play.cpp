#include "Play.h"
#include"Player.h"
#include"Sniper.h"
#include "Result.h"

// @brief PlaySceneコンストラクター //

Play::Play()
    :SceneBase()
    , cPos(VGet(0.0f, 40.0f, -70.0f))
    , cTarget(VGet(0.0f, 0.0f, 0.0f))
{
    BgHandle = LoadGraph("SourceCode/Assets/BackGround/Play.png");

    SetCameraNearFar(cNear, cFar);                      //カメラの描画範囲設定
    SetCameraPositionAndTarget_UpVecY(cPos, cTarget);   //視点からターゲットを見る角度にカメラ設置

    player = new Player();
}

// @brief PlaySceneデストラクター //

Play::~Play()
{
    if (BgHandle != -1)
    {
        DeleteGraph(BgHandle);
    }
}

// @biref PlayScene更新処理 //

SceneBase* Play::Update(float deltaTime)
{
    player->Update(deltaTime);

    putTime -= deltaTime;
    if (putTime < 0.0f&&GetMouseInput()&MOUSE_INPUT_LEFT)          //エンターキーが押されたら
    {
        for (int i = 0; i < 5; i++)             //ポインタの空きを検索
        {
            if (snpArray[i] == nullptr)         //空きを見つけたら
            {
                snpArray[i] = new Sniper();     //新規作成
                putTime = putInterval;
                break;                          //for文を抜ける
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

// @brief PlayScene描画処理 //

void Play::Draw()
{
    //---地面グリッドを描画---//(のちにゲームオブジェクトに移行)
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
    }//描画終わり

    //DrawGraph(BgX, BgY, BgHandle, TRUE);
    player->Draw();

    for (int i = 0; i < 5; i++)
    {
        if (snpArray[i] != nullptr)
        {
            snpArray[i]->Draw();
        }
    }
    DrawFormatString(0, 0, GetColor(255, 255, 255), "Play画面:RでResultシーンへ移行");
}