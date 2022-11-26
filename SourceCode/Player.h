#pragma once
#include<DxLib.h>
#include"Math.h"
#include"GameObject.h"


/*Player�̃N���X*/
class Player :public GameObject
{
public:
	/// <summary>
	/// Player�R���X�g���N�^�[
	/// </summary>
	Player();

	/// <summary>
	/// Player�f�X�g���N�^�[
	/// </summary>
	~Player();

	/// <summary>
	/// Player�X�V����
	/// </summary>
	/// <param name="deltaTime">:�t���[�����[�g</param>
	void Update(float deltaTime) override;

	/// <summary>
	/// Player�`�揈��
	/// </summary>
	void Draw() override;

private:
	VECTOR UP = { 0, 0, 0.9f };			//�O����
	VECTOR DOWN = { 0, 0, -0.9f };		//�����
	VECTOR RIGHT = { 0.9f, 0, 0 };		//�E����
	VECTOR LEFT = { -0.9f, 0, 0 };		//������

	VECTOR InputVec;	//�����x�N�g��
	bool KeyInput;		//�L�[���͔���
};

