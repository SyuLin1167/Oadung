#include "Player.h"
#include"Math.h"

// @brief Playerコンストラクター //

Player::Player()
    :plyHandle(-1)
    ,plyPos(VGet(0.0f, 0.0f, 0.0f))
    ,plyDir(VGet(0.0f,0.0f,1.0f))
    ,InputVec(VGet(0,0,0))
    ,KeyInput(false)
{
    plyHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");
}

// @brief Playerデストラクター //

Player::~Player()
{
    if (plyHandle != -1)
    {
        MV1DeleteModel(plyHandle);
    }
}

//@brief Player更新処理//

void Player::Update(float deltaTime)
{
    //---キー入力判定処理---//
    KeyInput = false;                           //未入力時は入力判定をFALSEに
    
    if (CheckHitKey(KEY_INPUT_LEFT))            //左キー入力
    {
        InputVec += LEFT;                       //ベクトル加算
        KeyInput = true;                        //入力判定をTRUEに
    }
    if (CheckHitKey(KEY_INPUT_RIGHT))           //右キー入力
    {
        InputVec += RIGHT;
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_UP))              //上キー入力
    {
        InputVec += UP;
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_DOWN))            //下キー入力
    {
        InputVec += DOWN;
        KeyInput = true;
    }


    //---移動処理---//
    if (KeyInput)
    {
        InputVec = VNorm(InputVec);                                 //ベクトルの方向成分を取得
        plyDir = InputVec;                                          //キャラの向き
        plyPos += InputVec * FirstSpeed * deltaTime;                //移動
    }
    
    MV1SetPosition(plyHandle, plyPos);                              //ポジション設定

    MATRIX RotMatY = MGetRotY(180 * (float)(DX_PI / 180.0f));       //逆向きなので180度回転
    MV1SetRotationZYAxis(plyHandle, VTransform(plyDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //モデル回転

}

// @brief Player描画処理 //

void Player::Draw()
{
    MV1DrawModel(plyHandle);
}