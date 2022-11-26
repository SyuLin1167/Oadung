#include "Player.h"

// @brief Playerコンストラクター //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
{
    objHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");     //モデル読み込み
    objDir = VGet(0.0f, 0.0f, 1.0f);        //初期方向
    objSpeed = 5.0f;                        //初期速度
}

// @brief Playerデストラクター //

Player::~Player()
{
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
        objDir = InputVec;                                          //キャラの向き
        objPos += InputVec * objSpeed * deltaTime;                //移動
    }
    
    MV1SetPosition(objHandle, objPos);                              //ポジション設定

    MATRIX RotMatY = MGetRotY(180 * (float)(DX_PI / 180.0f));       //逆向きなので180度回転
    MV1SetRotationZYAxis(objHandle, VTransform(objDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //モデル回転

}

// @brief Player描画処理 //

void Player::Draw()
{
    MV1DrawModel(objHandle);        //モデル描画
}