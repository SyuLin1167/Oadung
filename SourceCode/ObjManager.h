#pragma once
#include<vector>
#include<map>
#include<DxLib.h>

#include"GameObject.h"
#include"ObjectTag.h"
#include"Math/Math.h"

using namespace std;

/* オブジェクト管理クラス */
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
    /// <param name="newObj">:追加するオブジェクト</param>
    static void Entry(GameObject* newObj);

    /// <summary>
    /// オブジェクト削除
    /// </summary>
    /// <param name="releaseObj">:削除するオブジェクト</param>
    static void Release(GameObject* releaseObj); 

    /// <summary>
    /// 全オブジェクト削除
    /// </summary>
    static void ReleaceAllObj();

    /// <summary>
    /// 全オブジェクトの更新処理
    /// </summary>
    /// <param name="deltaTime">:フレームレート</param>
    static void Update(float deltaTime);

    /// <summary>
    /// オブジェクトの生死状況
    /// </summary>
    static void Dead();

    /// <summary>
    /// 全オブジェクトの描画処理
    /// </summary>
    static void Draw();

    /// <summary>
    /// ObjManagerの解放
    /// </summary>
    static void Finalize();

private:
    /// <summary>
    /// ObjManagerコンストラクター(シングルトン)
    /// </summary>
    ObjManager();

    /// <summary>
    /// ObjManagerデストラクター
    /// </summary>
    ~ObjManager();

    static ObjManager* objInstance;     //ObjManagerの実態
    vector<GameObject*>holdObj;         //一時待機オブジェクト
    vector<GameObject*>Object;          //Object[タグ種類][オブジェクト個数]
};

