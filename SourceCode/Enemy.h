#pragma once
#include<DxLib.h>

const float firstSpeed = 5.0f;       //�����x

    /*Enemy�̃N���X*/
class Enemy
{
public:
    /// <summary>
    /// Enemy�̃R���X�g���N�^�[
    /// </summary>
    Enemy();

    /// <summary>
    /// Enemy�̃f�X�g���N�^�[
    /// </summary>
    ~Enemy();

    /// <summary>
    /// Enemy�X�V����
    /// </summary>
    void Update(float deltaTime);

    /// <summary>
    /// Enemy�`�揈��
    /// </summary>
    void Draw();

    /// <summary>
    /// Enemy���S����
    /// </summary>
    /// <returns>���S�t���O</returns>
    bool IsDead() { return isDead; }

    /// <summary>
    /// Enemy���f���폜
    /// </summary>
    static void UnloadModel();

private:
    static int emyHandle;       //Enemy���f���n���h��
    int emyDuplicate;           //�������f��(�ǂݍ��ݕs�v)
    VECTOR emyPos;              //Enemy���W
    VECTOR emyDir;              //Enemy����
    bool isDead;                //���S�t���O
};

