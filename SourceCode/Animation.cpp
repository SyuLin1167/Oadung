#include "Animation.h"
//#include"AssetManager"

// @brief Animationコンストラクター //

Animation::Animation(int modelHandle)
    :modelHandle(modelHandle)
    ,nowAnimType(-1)
    ,nowAnimTime(0.0f)
    ,attachedIndex(0)
{
}

// @brief Animationデストラクター //

Animation::~Animation()
{
}

// @brief アニメーション追加処理 //

int Animation::AddAnimation(string fileName, float animFps, bool animLoop)
{
    AnimData anim = {};                     //アニメーションデータ
    anim.animFps = animFps;                 //フレームレートは引数から代入
    anim.isLoop = animLoop;                 //ループ再生フラグは引数から代入

    anim.animHandle;
}