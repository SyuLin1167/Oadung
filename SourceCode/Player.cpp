#include "Player.h"
#include"ObjManager.h"
#include "Archer.h"

// @brief Playerコンストラクター //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
{
    objHandle = MV1LoadModel("SourceCode/Assets/Player/PlayerModel.mv1");     //モデル読み込み
    MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));							//モデルのサイズ設定
    objDir = VGet(0.0f, 0.0f, 1.0f);        //初期方向
    objSpeed = 5.0f;                        //初期速度

    //---当たり判定球設定---//
    colSphere.localCenter = VGet(0, 10, 0);			//ローカル座標
    colSphere.Radius = 5.0f;						//球半径
    colSphere.worldCenter = objPos;					//ワールド座標
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
        objPos += InputVec * objSpeed * deltaTime;                  //移動
    }
    
    MV1SetPosition(objHandle, objPos);                              //ポジション設定

    MATRIX RotMatY = MGetRotY(180.0f * (float)(DX_PI / 180.0f));       //逆向きなので180度回転
    VECTOR negativeVec = VTransform(objDir, RotMatY);
    MV1SetRotationZYAxis(objHandle, negativeVec,
        VGet(0.0f, 1.0f, 0.0f), 0.0f);         //モデル回転

    colSphere.Move(objPos);					//当たり判定の移動

    putTime -= deltaTime;
    if (putTime < 0.0f && GetMouseInput() & MOUSE_INPUT_LEFT)          //左クリックしたら
    {

        archer = new Archer(this);     //新規作成
        ObjManager::Entry(archer);
        putTime = putInterval;
    }
    if (archer != nullptr)
    {
        //---当たり判定球取得---//
        Sphere sArc, sPly;
        sArc = archer->GetColSphere();
        sPly = this->GetColSphere();

        if (CollisionPair(sArc, sPly))
        {
            archer->SetAlive(false);
        }
    }
}

// @brief Player描画処理 //

void Player::Draw()
{
    MV1DrawModel(objHandle);        //モデル描画

        //---当たり判定デバッグ描画(後で消す)---//
    DrawSphere3D(colSphere.worldCenter, colSphere.Radius, 8, GetColor(0, 255, 255), 0, FALSE);
}