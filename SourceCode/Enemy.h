#pragma once
#include<DxLib.h>

const float firstSpeed = 5.0f;       //初速度

    /*Enemyのクラス*/
class Enemy
{
public:
    /// <summary>
    /// Enemyのコンストラクター
    /// </summary>
    Enemy();

    /// <summary>
    /// Enemyのデストラクター
    /// </summary>
    ~Enemy();

    /// <summary>
    /// Enemy更新処理
    /// </summary>
    void Update(float deltaTime);

    /// <summary>
    /// Enemy描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// Enemy死亡判定
    /// </summary>
    /// <returns>死亡フラグ</returns>
    bool IsDead() { return isDead; }

    /// <summary>
    /// Enemyモデル削除
    /// </summary>
    static void UnloadModel();

private:
    static int emyHandle;       //Enemyモデルハンドル
    int emyDuplicate;           //複製モデル(読み込み不要)
    VECTOR emyPos;              //Enemy座標
    VECTOR emyDir;              //Enemy方向
    bool isDead;                //死亡フラグ
};

