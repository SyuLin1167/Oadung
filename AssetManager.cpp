#include "AssetManager.h"

AssetManager* AssetManager::assetInstance = nullptr;    //AssetManager実態へのポインタ定義

// @brief AssetManagerコンストラクター //

AssetManager::AssetManager()
{
    assetInstance = nullptr;
}

// @brief AssetManagerデストラクター //

AssetManager::~AssetManager()
{
    assetInstance->ReleaseAllAsset();       //すべてのアセットを削除
    assetInstance = nullptr;                //ポインタを削除
}

// @brief AssetManager初期化 //

void AssetManager::Initialize()
{
    if (!assetInstance)                     //ポインタが空だったら
    {
        assetInstance = new AssetManager;   //ポインタ初期化
    }
}

// @brief メッシュの取得 //

int AssetManager::GetMesh(string meshFileName)
{
    auto iter = assetInstance->meshMap.find(meshFileName);

    if (iter == assetInstance->meshMap.end())
    {
        meshID = MV1LoadModel(meshFileName.c_str());
    }
}