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
	void Update();

	/// <summary>
	/// Player�`�揈��
	/// </summary>
	void Draw();

private:
	int PlyHandle;			//Player�摜�n���h��
	VECTOR PlayerPos;		//Player���W
};

