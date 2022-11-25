#include "Enemy.h"
#include"Math.h"

int Enemy::emyHandle = -1;

/* @brief Enemyコンストラクタ */

Enemy::Enemy()
    :emyPos(VGet(10.0f,0.0f,0.0f))
    ,emyDir(VGet(-1.0f,0.0f,0.0f))
    ,isDead(false)
{
    emyHandle = MV1LoadModel("SourceCode/Assets/Enemy/SampleEnemy.MV1");		//モデル読み込み
    emyDuplicate = MV1DuplicateModel(emyHandle);								//モデル複製
    MV1SetScale(emyDuplicate, VGet(0.1f, 0.1f, 0.1f));							//モデルのサイズ設定
    MV1SetPosition(emyDuplicate, emyPos);										//ポジション設定
}

// @brief Enemyデストラクター //

Enemy::~Enemy()
{
    if (emyDuplicate != -1)
    {
        MV1DeleteModel(emyDuplicate);
    }
}

// @brief Enemy更新処理 //

void Enemy::Update(float deltaTime)
{
    emyPos += emyDir * firstSpeed * deltaTime;                //移動
    MV1SetPosition(emyDuplicate, emyPos);                        //ポジション設定
    MATRIX RotMatY = MGetRotY(90 * (float)(DX_PI / 90.0f));       //左向きに回転させる
    MV1SetRotationZYAxis(emyDuplicate, VTransform(emyDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //モデル回転
}

// @brief Enemy描画処理 //

void Enemy::Draw()
{
    MV1DrawModel(emyDuplicate);
}

// @brief Enemyモデル削除 //

void Enemy::UnloadModel()
{
    if (emyHandle != -1)
    {
        MV1DeleteModel(emyHandle);
    }
}

