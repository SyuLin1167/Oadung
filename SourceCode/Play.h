#pragma once
#include "DxLib.h"
#include"SceneBase.h"

const float cNear = 0.1f;       //�J�����̕`��͈�(��)
const float cFar = 1000.0f;     //�J�����̕`��͈�(��)

class Player;

/*�v���C�V�[���̃N���X*/
class Play :public SceneBase
{
    Player* player;
public:
    /// <summary>
    /// �R���X�g���N�^�[
    /// </summary>
    Play();

    /// <summary>
    /// �f�X�g���N�^�[
    /// </summary>
    ~Play();

    /// <summary>
    /// PlayScene�X�V����
    /// </summary>
    /// <param name="deltaTime"></param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float deltaTime)override;

    /// <summary>
    /// �v���C�V�[���̕`��
    /// </summary>
    void Draw()override;

private:
    VECTOR cPos;            //�J�����̎��_�ʒu
    VECTOR cTarget;         //�J�����̒����_�ʒu
};

