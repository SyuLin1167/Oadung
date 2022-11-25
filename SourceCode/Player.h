#pragma once
#include<DxLib.h>

const float FirstSpeed = 5.0f;	//�������x

/*Player�̃N���X*/
class Player
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
	void Update(float deltaTime);

	/// <summary>
	/// Player�`�揈��
	/// </summary>
	void Draw();

private:
	int plyHandle;		//Player���f���n���h��
	VECTOR plyPos;		//Player���W
	VECTOR plyDir;		//Player����

	VECTOR UP = { 0, 0, 0.9f };			//�O����
	VECTOR DOWN = { 0, 0, -0.9f };		//�����
	VECTOR RIGHT = { 0.9f, 0, 0 };		//�E����
	VECTOR LEFT = { -0.9f, 0, 0 };		//������

	VECTOR InputVec;	//�����x�N�g��
	bool KeyInput;		//�L�[���͔���
};

