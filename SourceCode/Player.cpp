#include "Player.h"


//@brief Playerコンストラクター//

Player::Player()
    :PlyHandle(-1)
    , PlyPos(VGet(0.0f, 0.0f, 0.0f))
    ,PlyDir(VGet(0.0f,0.0f,1.0f))
    ,InputVec(VGet(0,0,0))
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

void Player::Update(float deltaTime)
{
    //キー入力判定処理//
    KeyInput = false;                           //未入力時は入力判定をFALSEに
    
    if (CheckHitKey(KEY_INPUT_LEFT))            //左キー入力
    {
        InputVec = VAdd(InputVec, LEFT);        //ベクトル加算
        KeyInput = true;                        //入力判定をTRUEに
    }
    if (CheckHitKey(KEY_INPUT_RIGHT))           //右キー入力
    {
        InputVec = VAdd(InputVec, RIGHT);
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_UP))              //上キー入力
    {
        InputVec = VAdd(InputVec, UP);
        KeyInput = true;
    }
    if (CheckHitKey(KEY_INPUT_DOWN))            //下キー入力
    {
        InputVec = VAdd(InputVec, DOWN);
        KeyInput = true;
    }


    //移動処理//
    if (KeyInput)
    {
        InputVec = VNorm(InputVec);             //ベクトルの方向成分を取得
        PlyDir = InputVec;                      //キャラの向き
        PlyPos = VAdd(PlyPos, VScale(InputVec, FirstSpeed * deltaTime));    //移動
    }
    
    MV1SetPosition(PlyHandle, PlyPos);          //ポジション設定

    MATRIX RotMatY = MGetRotY(180 - (DX_PI / 180.0f));                      //逆向きなので180度回転


}

//@brief Player描画処理

void Player::Draw()
{
    MV1DrawModel(PlyHandle);
}