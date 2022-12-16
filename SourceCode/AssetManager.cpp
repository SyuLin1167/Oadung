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

void AssetManager::Init()
{
    if (!assetInstance)                     //�|�C���^���󂾂�����
    {
        assetInstance = new AssetManager;   //�|�C���^������
    }
}

// @brief ���b�V���̎擾 //

int AssetManager::GetMesh(string meshFileName)
{
    int meshID = 0;
    //---���b�V���o�^---//
    auto iter = assetInstance->meshMap.find(meshFileName);   //�t�@�C�����o�^����Ă��邩�ǂ�������

    if (iter == assetInstance->meshMap.end())                                               //�o�^����Ă��Ȃ�������
    {
        meshID = MV1LoadModel(meshFileName.c_str());                                        //�V�K�t�@�C���ǂݍ���
        if (meshID == -1)                                                                   //ID���󂾂�����
        {
            return meshID;                                                                  //ID��Ԃ�
        }
        assetInstance->meshMap.emplace(meshFileName, meshID);                //�t�@�C����ID�Ƌ��ɓo�^
    }

    //---�����������b�V����ԋp---//
    meshID = MV1DuplicateModel(assetInstance->meshMap[meshFileName]);             //���b�V�������AID�ɑ��
    assetInstance->duplicateMesh.push_back(meshID);                                   //�����𖖔��ɒǉ�
    return meshID;                                                                         //��������ID��Ԃ�
}

// @brief �A�j���[�V�����̎擾 //

int AssetManager::GetAnim(string animFileName)
{
    int animID = 0;
    //---�A�j���[�V�����o�^---//
    auto iter = assetInstance->animMap.find(animFileName);  //�t�@�C�����o�^����Ă��邩�ǂ�������

    if (iter == assetInstance->animMap.end())                                             //�o�^����Ă��Ȃ�������
    {
        animID = MV1LoadModel(animFileName.c_str());                                      //�V�K�t�@�C���ǂݍ���
        if (animID == -1)                                                                 //ID���󂾂�����
        {
            return animID;                                                                //ID��Ԃ�
        }
        assetInstance->animMap.emplace(animFileName, animID);               //�t�@�C����ID�Ƌ��ɓo�^
    }

    return animID;                                          //�A�j���[�V����ID��Ԃ�
}

// @brief ���b�V���̍폜 //

void AssetManager::ReleaseMesh(int meshID)
{
    auto iter = find(assetInstance->duplicateMesh.begin(),
        assetInstance->duplicateMesh.end(), meshID);                            //�������ꂽ���b�V����������
    if (iter == assetInstance->duplicateMesh.end())                                        //������Ȃ�������
    {
        return;                                                                            //���ʂ�Ԃ�
    }
    MV1DeleteModel(meshID);                                                         //���b�V���폜

    iter_swap(iter, assetInstance->duplicateMesh.end() - 1);                   //�����̃f�[�^�Ɠ���ւ���
    assetInstance->duplicateMesh.pop_back();                                                //�����̃f�[�^���폜
}

// @brief �S�A�Z�b�g�̍폜 //

void AssetManager::ReleaseAllAsset()
{
    //---�A�j���[�V�������---//
    for (auto anim : assetInstance->animMap)
    {
        MV1DeleteModel(anim.second);
    }

    //---���b�V�����---//
    for (auto mesh : assetInstance->meshMap)
    {
        MV1DeleteModel(mesh.second);
    }

    //---�������---//
    for (auto dup : assetInstance->duplicateMesh)
    {
        MV1DeleteModel(dup);
    }

    assetInstance->animMap.clear();             //�A�j���[�V�����̂��ׂĂ̗v�f���폜
    assetInstance->meshMap.clear();             //���b�V���̂��ׂĂ̗v�f���폜
    assetInstance->duplicateMesh.clear();       //�������b�V���̂��ׂĂ̗v�f���폜
}

// @brief AssetManager�̉�� //

void AssetManager::Finalize()
{
    ReleaseAllAsset();
    if (assetInstance)                          //�|�C���^���󂶂�Ȃ�������
    {
        delete assetInstance;                   //���g���폜
    }
}