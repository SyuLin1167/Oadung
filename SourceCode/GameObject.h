#pragma once
#include<DxLib.h>
#include"Math.h"

/*親クラス*/
class GameObject
{
public:
    /// <summary>
    /// コンストラクター
    /// </summary>
    GameObject();

    /// <summary>
    /// デストラクター
    /// </summary>
    virtual ~GameObject();

    /// <summary>
    /// 座標取得
    /// </summary>
    /// <returns>セットされた座標</returns>
    const VECTOR& GetPosition()const { return Position; }

    /// <summary>
    /// 座標設定
    /// </summary>
    /// <param name="setPos">:座標にセットする値</param>
    void SetPosition(const VECTOR setPos) { Position = setPos; }

    /// <summary>
    /// 方向取得
    /// </summary>
    /// <returns>セットされた向き</returns>
    const VECTOR& GetDir()const { return Dir; }

    /// <summary>
    /// 方向設定
    /// </summary>
    /// <param name="dir">:向きにセットする値</param>
    void SetDir(const VECTOR dir) { Dir = dir; }

    /// <summary>
    /// 生死判定
    /// </summary>
    /// <returns>生死状態</returns>
    bool IsAlive() { return isAlive; }

    /// <summary>
    /// 生死設定
    /// </summary>
    /// <param name="alive">:生きているかどうか</param>
    void SetAlive(bool alive) { isAlive = alive; }

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    virtual void Update(float deltaTime) = 0;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw();

protected:
    VECTOR Position;        //ワールド座標
    VECTOR Dir;             //ワールド方向
    int modelHandle;        //モデルハンドル
    bool isAlive;           //生死状態
};

