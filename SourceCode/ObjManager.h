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
    /// ObjManager����������
    /// </summary>
    static void Init();

    /// <summary>
    /// �I�u�W�F�N�g�o�^
    /// </summary>
    /// <param name="newObj">�I�u�W�F�N�g</param>
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
    ///�S�I�u�W�F�N�g�̍X�V����
    /// </summary>
    /// <param name="deltaTime">�t���[�����[�g</param>
    static void Update(float deltaTime);


    static void Draw();

    static void Finalize();
};

