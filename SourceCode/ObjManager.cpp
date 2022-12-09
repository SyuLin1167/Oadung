#include "ObjManager.h"
#include"GameObject.h"

ObjManager* ObjManager::objInstance = nullptr;				//ObjManager実体へのポインタ定義

// @brief ObjManagerコンストラクター //

ObjManager::ObjManager()
	:Object()
{
	objInstance = nullptr;
}

// @brief ObjManagerデストラクター //

ObjManager::~ObjManager()
{
	ReleaceAllObj();
}

// @brief ObjManager初期化処理 //

void ObjManager::Init()
{
	if (!objInstance)										//ポインタが空だったら
	{
		objInstance = new ObjManager;						//ポインタ初期化
	}
}

// @brief オブジェクト登録 //

void ObjManager::Entry(GameObject*newObj)
{
	objInstance->holdObj.emplace_back(newObj);				//オブジェクト一時保存
}

//@brief オブジェクト削除 //

void ObjManager::Release(GameObject* releaseObj)
{
	auto iter = find(objInstance->holdObj.begin(),
		objInstance->holdObj.end(), releaseObj);			//一時保存オブジェクト内を検索

	if (iter != objInstance->holdObj.end())					//オブジェクトが見つかったら
	{
		iter_swap(iter, objInstance->holdObj.end() - 1);	//見つけたオブジェクトを最後尾に移動
		objInstance->holdObj.pop_back();					//データを削除

		//objInstance->holdObj.erase(iter);					//-----------------------この書き方じゃダメなのか
		return;
	}

	iter = find(objInstance->Object.begin(),
		objInstance->Object.end(), releaseObj);				//アクティブオブジェクト内を検索

	if (iter != objInstance->Object.end())					//オブジェクトが見つかったら
	{
		iter_swap(iter, objInstance->Object.end() - 1);		//見つけたオブジェクトを末尾に移動
		delete objInstance->Object.back();					//オブジェクト削除
	}
}

// @brief 全オブジェクト削除 //

void ObjManager::ReleaceAllObj()
{
	while (!objInstance->holdObj.empty())					//一時保存オブジェクト内が空になるまで
	{
		delete objInstance->holdObj.back();					//末尾から削除	---------ここはpop_backじゃないのか
	}

	while (!objInstance->Object.empty())					//アクティブオブジェクト内が空になるまで
	{
		delete objInstance->Object.back();					//末尾から削除
		objInstance->Object.pop_back();						//-----------------------なぜこの文が必要なのか
	}
}

// @brief 全オブジェクトの更新処理 //

void ObjManager::Update(float deltaTime)
{
	for (auto obj : objInstance->Object)			//すべてのアクターの更新
	{
		obj->Update(deltaTime);						//該当タグにある全てのオブジェクトを更新
	}

	for (auto holding : objInstance->holdObj)
	{
		objInstance->Object.emplace_back(holding);	//一時保存中のオブジェクトをアクティブリストに追加
	}
	objInstance->holdObj.clear();					//追加し終えたので一時保存オブジェクト内をすべて空にする

	Dead();
}

// @brief オブジェクトの生死状況 //

void ObjManager::Dead()
{
	vector<GameObject*>deadObj;									//死亡オブジェクト
	for (int i = 0; i < objInstance->Object.size(); ++i)		//死亡オブジェクト検索
	{
		if (!objInstance->Object[i]->IsAlive())					//オブジェクトが生きていなかったら
		{
			deadObj.emplace_back(objInstance->Object[i]);		//死亡オブジェクトへ追加
		}
	}

	for (auto dead : deadObj)
	{
		delete dead;											//死んでいるオブジェクトを全て削除
	}
	deadObj.clear();											//削除し終えたので死亡オブジェクト内を全て空にする
}

// @brief 全オブジェクトの描画処理 //

void ObjManager::Draw()
{
	for (int i = 0; i < objInstance->Object.size(); ++i)		//全てのアクターの描画
	{
		objInstance->Object[i]->Draw();							//該当タグにある全てのオブジェクトを描画
	}
}

// @brief ObjManagerの開放 //

void ObjManager::Finalize()
{
	ReleaceAllObj();					//全てのオブジェクトを削除
	if (objInstance)					//インスタンスの中身があったら
	{
		delete objInstance;				//削除
		objInstance = nullptr;			//中身を空にする
	}
}