#pragma once
#include"SceneBase.h"

/*���U���g�V�[���̃N���X*/
class Result :public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Result();

	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Result();

	/// <summary>
	/// ResultScene�X�V����
	/// </summary>
	/// <param name="deltaTime"></param>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase* Update(float deltaTime)override;

	/// <summary>
	/// ���U���g�V�[���̕`��
	/// </summary>
	void Draw()override;

};
