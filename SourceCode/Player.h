#pragma once
#include"DxLib.h"

const int FirstSpeed = 2;	//�������x

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
	int PlyHandle;		//Player�摜�n���h��
	VECTOR PlyPos;		//Player���W
	VECTOR PlyDir;		//Player����

	VECTOR UP = { 0, 0, 1 };		//�O����
	VECTOR DOWN = { 0, 0, -1 };		//�����
	VECTOR RIGHT = { 1, 0, 0 };		//�E����
	VECTOR LEFT = { -1, 0, 0 };		//������

	VECTOR InputVec;	//�����x�N�g��
	bool KeyInput;		//�L�[���͔���
};
