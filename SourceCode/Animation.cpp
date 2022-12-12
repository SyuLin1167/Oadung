#include "Animation.h"
#include"AssetManager.h"

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

int Animation::AddAnimation(string animFileName, float animFps, bool animLoop)
{
    AnimData anim = {};                     //アニメーションデータ
    anim.animFps = animFps;                 //フレームレートは引数から代入
    anim.isLoop = animLoop;                 //ループ再生フラグは引数から代入

    anim.animHandle = AssetManager::GetAnim(animFileName.c_str());      //アニメーションデータ読み込み
    if (anim.animHandle == -1)                                          //データが入っていなかったら
    {
        return -1;                                                      //入っていないという結果を返す
    }

    anim.animIndex = MV1GetAnimNum(anim.animHandle) - 1;                //アニメーションの個数からインデックスを得る

    attachedIndex = MV1AttachAnim(modelHandle, anim.animIndex,
        anim.animHandle, TRUE);                    //アニメーションをモデルに追加

    anim.totalTime = MV1GetAnimTotalTime(modelHandle, anim.animIndex);      //アニメーション再生時間取得


}