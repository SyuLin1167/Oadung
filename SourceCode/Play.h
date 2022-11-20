#pragma once
#include "DxLib.h"
#include"SceneBase.h"

const float cNear = 1.0f;       //カメラの描画範囲(近)
const float cFar = 2000.0f;     //カメラの描画範囲(遠)

//---地面グリッド描画定数---//(のちにゲームオブジェクトに移行)
const float gridAllSize = 100.0f;
const int divideNum = 10;
const float gridSpace = gridAllSize / divideNum;

class Player;

/*プレイシーンのクラス*/
class Play :public SceneBase
{
    Player* player;
public:
    /// <summary>
    /// コンストラクター
    /// </summary>
    Play();

    /// <summary>
    /// デストラクター
    /// </summary>
    ~Play();

    /// <summary>
    /// PlayScene更新処理
    /// </summary>
    /// <param name="deltaTime"></param>
    /// <returns>現在のシーンのポインタ</returns>
    SceneBase* Update(float deltaTime)override;

    /// <summary>
    /// プレイシーンの描画
    /// </summary>
    void Draw()override;

private:
    VECTOR cPos;            //カメラの視点位置
    VECTOR cTarget;         //カメラの注視点位置

    //---地面グリッド描画変数---//(のちにゲームオブジェクトに移行)
    VECTOR p1;
    VECTOR p2;
};

