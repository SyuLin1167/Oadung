#pragma once
#include<vector>
#include<map>
#include<DxLib.h>

#include"GameObject.h"
#include"ObjectTag.h"
#include"Math/Math.h"

class ObjManager final
{
public:
    /// <summary>
    /// ObjManager初期化処理
    /// </summary>
    static void Init();

    /// <summary>
    /// オブジェクト登録
    /// </summary>
    /// <param name="newObj">オブジェクト</param>
    static void Entry(GameObject* newObj);

    /// <summary>
    /// オブジェクト削除
    /// </summary>
    /// <param name="releaseObj">削除するオブジェクト</param>
    static void Release(GameObject* releaseObj); 

    /// <summary>
    /// 全オブジェクト削除
    /// </summary>
    static void ReleaceAllObj();

    /// <summary>
    ///全オブジェクトの更新処理
    /// </summary>
    /// <param name="deltaTime">フレームレート</param>
    static void Update(float deltaTime);


    static void Draw();

    static void Finalize();
};

