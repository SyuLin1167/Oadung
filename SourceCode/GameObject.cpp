#include "GameObject.h"

// @brief コンストラクター //

GameObject::GameObject()
    :Position()
    ,Dir()
    ,modelHandle(-1)
    ,isAlive(true)
{
}

// @brief デストラクター //
GameObject::~GameObject()
{
    if (modelHandle != -1)
    {
        MV1DeleteModel(modelHandle);
    }
}

// @brief 描画処理 //

void GameObject::Draw()
{
}