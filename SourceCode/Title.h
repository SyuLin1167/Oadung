#pragma once
#include "SceneBase.h"

/*�^�C�g���V�[���̃N���X*/
class Title :public SceneBase
{
public:
    /// <summary>
    /// �R���X�g���N�^�[
    /// </summary>
    Title();

    /// <summary>
    /// �f�X�g���N�^�[
    /// </summary>
    ~Title();

    /// <summary>
    /// TitleScene�X�V����
    /// </summary>
    /// <param name="deltaTime"></param>
    /// <returns>���݂̃V�[���̃|�C���^</returns>
    SceneBase* Update(float deltaTime)override;

    /// <summary>
    /// �^�C�g���V�[���̕`��
    /// </summary>
    void Draw()override;

};

