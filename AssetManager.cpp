#include "AssetManager.h"

AssetManager* AssetManager::assetInstance = nullptr;    //AssetManager���Ԃւ̃|�C���^��`

// @brief AssetManager�R���X�g���N�^�[ //

AssetManager::AssetManager()
{
    assetInstance = nullptr;
}

// @brief AssetManager�f�X�g���N�^�[ //

AssetManager::~AssetManager()
{
    assetInstance->ReleaseAllAsset();       //���ׂẴA�Z�b�g���폜
    assetInstance = nullptr;                //�|�C���^���폜
}

// @brief AssetManager������ //

void AssetManager::Initialize()
{
    if (!assetInstance)                     //�|�C���^���󂾂�����
    {
        assetInstance = new AssetManager;   //�|�C���^������
    }
}

// @brief ���b�V���̎擾 //

int AssetManager::GetMesh(string meshFileName)
{
    auto iter = assetInstance->meshMap.find(meshFileName);

    if (iter == assetInstance->meshMap.end())
    {
        meshID = MV1LoadModel(meshFileName.c_str());
    }
}