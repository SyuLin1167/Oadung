#pragma once
#include<vector>
#include<map>
#include<DxLib.h>

#include"GameObject.h"
#include"ObjectTag.h"
#include"Math/Math.h"

using namespace std;

class ObjManager final
{
public:
    /// <summary>
    /// ObjManager����������
    /// </summary>
    static void Init();

    /// <summary>
    /// �I�u�W�F�N�g�o�^
    /// </summary>
    /// <param name="newObj">�ǉ�����I�u�W�F�N�g</param>
    static void Entry(GameObject* newObj);

    /// <summary>
    /// �I�u�W�F�N�g�폜
    /// </summary>
    /// <param name="releaseObj">�폜����I�u�W�F�N�g</param>
    static void Release(GameObject* releaseObj); 

    /// <summary>
    /// �S�I�u�W�F�N�g�폜
    /// </summary>
    static void ReleaceAllObj();

    /// <summary>
    /// �S�I�u�W�F�N�g�̍X�V����
    /// </summary>
    /// <param name="deltaTime">�t���[�����[�g</param>
    static void Update(float deltaTime);

    /// <summary>
    /// �I�u�W�F�N�g�̐�����
    /// </summary>
    static void Dead();

    /// <summary>
    /// �S�I�u�W�F�N�g�̕`�揈��
    /// </summary>
    static void Draw();

    /// <summary>
    /// ObjManager�̊J��
    /// </summary>
    static void Finalize();

private:
    /// <summary>
    /// ObjManager�R���X�g���N�^�[(�V���O���g��)
    /// </summary>
    ObjManager();

    /// <summary>
    /// ObjManager�f�X�g���N�^�[
    /// </summary>
    ~ObjManager();

    static ObjManager* objInstance;     //ObjManager�̎���
    vector<GameObject*>holdObj;         //�ꎞ�ҋ@�I�u�W�F�N�g
    vector<GameObject*>Object;          //Object[�^�O���][�I�u�W�F�N�g��]
};

