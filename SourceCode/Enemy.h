#pragma once
#include<DxLib.h>
#include"GameObject.h"

/*Enemy�̃N���X*/
class Enemy :public GameObject
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
    /// <param name="deltaTime">:�t���[�����[�g</param>
    void Update(float deltaTime);

    /// <summary>
    /// Enemy�`�揈��
    /// </summary>
    void Draw();

private:

};

