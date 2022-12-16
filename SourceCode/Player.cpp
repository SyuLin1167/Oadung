#include "Player.h"

#include "Archer.h"

// @brief Playerコンストラクター //

Player::Player()
    :GameObject(ObjectTag::Player)
    ,InputVec(VGet(0.0f,0.0f,0.0f))
    ,KeyInput(false)
    ,animType(IDLE)
{
    //---モデル読み込み---//
    objHandle =AssetManager::GetMesh("SourceCode/Assets/Player/PlayerModel.mv1");       //モデル読み込み
    MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));                                     //モデルのサイズ設定

    plyAnim = new Animation(objHandle);                                                 //アニメーションのインスタンス

    //---アニメーション読み込み---//
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Idle.mv1");             //待機:0
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Run.mv1");              //走る:1
    plyAnim->AddAnimation("SourceCode/Assets/Player/PlayerModel_Atack.mv1",false);            //攻撃:2

    //---アニメーション状態セット---//
    animType = IDLE;
    plyAnim->StartAnim(IDLE);

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
    delete plyAnim;                         //アニメーション解放
}

//@brief Player更新処理//

void Player::Update(float deltaTime)
{
    plyAnim->AddAnimTime(deltaTime);            //現在のアニメーション再生を進める

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

        if (animType != RUN)
        {
            animType = RUN;
            plyAnim->StartAnim(RUN);
        }
    }
    else
    {
        if (animType != IDLE)
        {
            animType = IDLE;
            plyAnim->StartAnim(IDLE);
        }
    }

    MV1SetPosition(objHandle, objPos);                              //ポジション設定

    MATRIX RotMatY = MGetRotY(180.0f * (float)(DX_PI / 180.0f));       //逆向きなので180度回転
    VECTOR negativeVec = VTransform(objDir, RotMatY);
    MV1SetRotationZYAxis(objHandle, negativeVec,
        VGet(0.0f, 1.0f, 0.0f), 0.0f);         //モデル回転

    colSphere.Move(objPos);					//当たり判定の移動

    putTime -= deltaTime;
    if (putTime < 0.0f && GetMouseInput() & MOUSE_INPUT_LEFT)           //左クリックしたら
    {

        archer = new Archer(this);                                      //新規作成
        ObjManager::Entry(archer);                                  //配列に追加
        putTime = putInterval;
    }
    if (archer != nullptr)                                              //インスタンスの中身が空でなければ
    {
        //---当たり判定球取得---//
        Sphere sArc, sPly;
        sArc = archer->GetColSphere();                                  //アーチャーの当たり判定球取得
        sPly = this->GetColSphere();                                    //プレイヤーの当たり判定球取得

        if (CollisionPair(sArc, sPly))                      //球体同士の当たり判定
        {
            archer->SetAlive(false);                                //当たっていたら死亡
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