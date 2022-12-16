#pragma once
#include<DxLib.h>
#include<string>
#include<unordered_map>

using namespace std;

/* �A�Z�b�g�Ǘ��N���X */
class AssetManager
{
public:
    /// <summary>
    /// AssetManager����������
    /// </summary>
    static void Init();

    /// <summary>
    /// ���b�V���̎擾
    /// </summary>
    /// <param name="fileName">:���b�V���t�@�C����</param>
    /// <returns></returns>
    static int GetMesh(string meshFileName);

    /// <summary>
    /// �A�j���[�V�����̎擾
    /// </summary>
    /// <param name="fileName">:�A�j���[�V�����t�@�C����</param>
    /// <returns></returns>
    static int GetAnim(string animFileName);

    /// <summary>
    /// ���b�V���̍폜
    /// </summary>
    /// <param name="meshID">:���b�V��ID</param>
    static void ReleaseMesh(int meshID);

    /// <summary>
    /// �S�A�Z�b�g�̍폜
    /// </summary>
    static void ReleaseAllAsset();

    /// <summary>
    /// AssetManager�̉��
    /// </summary>
    static void Finalize();

private:
    /// <summary>
    /// AssetManager�R���X�g���N�^�[(�V���O���g��)
    /// </summary>
    AssetManager();

    /// <summary>
    /// AssetManager�f�X�g���N�^�[
    /// </summary>
    ~AssetManager();

    static AssetManager* assetInstance;     //AssetManager�̎���
    unordered_map<string, int>meshMap;      //���b�V��(�I���W�i��)
    unordered_map<string, int>animMap;      //�A�j���[�V����(�I���W�i��)
    vector<int> duplicateMesh;              //���b�V��(�R�s�[)
};

