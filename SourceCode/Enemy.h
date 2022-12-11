#pragma once
#include<DxLib.h>
#include"GameObject.h"

/*Enemyのクラス*/
class Enemy :public GameObject
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
    /// <param name="deltaTime">:フレームレート</param>
    void Update(float deltaTime);

    /// <summary>
    /// Enemy描画処理
    /// </summary>
    void Draw();

private:

};

