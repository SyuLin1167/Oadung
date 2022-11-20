#pragma once
#include "DxLib.h"
#include"SceneBase.h"

const float cNear = 1.0f;       //�J�����̕`��͈�(��)
const float cFar = 2000.0f;     //�J�����̕`��͈�(��)

//---�n�ʃO���b�h�`��萔---//(�̂��ɃQ�[���I�u�W�F�N�g�Ɉڍs)
const float gridAllSize = 100.0f;
const int divideNum = 10;
const float gridSpace = gridAllSize / divideNum;

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

    //---�n�ʃO���b�h�`��ϐ�---//(�̂��ɃQ�[���I�u�W�F�N�g�Ɉڍs)
    VECTOR p1;
    VECTOR p2;
};

