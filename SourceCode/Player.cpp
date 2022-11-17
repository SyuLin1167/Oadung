#include "Player.h"


//@brief Playerコンストラクター//

Player::Player()
    :PlyHandle(-1)
    , PlyPos(VGet(0.0f, 0.0f, 0.0f))
    ,PlyDir(VGet(0.0f,0.0f,1.0f))
    ,KeyInput(false)
{
    PlyHandle = MV1LoadModel("SourceCode/Assets/Player/hackadoll.pmx");
}

//@brief Playerデストラクター//

Player::~Player()
{
    if (PlyHandle != -1)
    {
        MV1DeleteModel(PlyHandle);
    }
}

//@brief Player更新処理

void Player::Update()
{
    MV1SetPosition(PlyHandle, PlyPos);       //ポジション設定

    //移動処理//
    if (CheckHitKey(KEY_INPUT_LEFT))            //左移動
    {
        if (PlyPos.x > -10)
        {
            PlyPos.x -= FirstSpeed;
        }
    }
    else if (CheckHitKey(KEY_INPUT_RIGHT))      //右移動
    {
        if (PlyPos.x < 10)
        {
            PlyPos.x += FirstSpeed;
        }
    }
    else if (CheckHitKey(KEY_INPUT_UP))         //上移動
    {
        PlyPos.z += FirstSpeed;
    }
    else if (CheckHitKey(KEY_INPUT_DOWN))       //下移動
    {
        PlyPos.z -= FirstSpeed;
    }

}

//@brief Player描画処理

void Player::Draw()
{
    MV1DrawModel(PlyHandle);
}