#pragma once
#include <DxLib.h>



/*Bow�̃N���X*/
class Bow
{
public:
	/// <summary>
	/// Bow�R���X�g���N�^�\
	/// </summary>
	Bow();

	/// <summary>
	/// Bow�f�X�g���N�^�\
	/// </summary>
	~Bow();

	/// <summary>
	/// Bow�X�V����
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Bow�`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// Bow���S����
	/// </summary>
	/// <returns>���S�t���O</returns>
	bool IsDead() { return isDead; }

	/// <summary>
	/// Bow���f���폜
	/// </summary>
	static void UnloadModel();

private:
	static int bowHandle;		//Bow���f���n���h��
	int bowDuplicate;			//�������f��(�ǂݍ��ݕs�v)
	VECTOR bowPos;				//Bow���W

	bool isDead;				//���S�t���O

	int MouseX;					//�}�E�X���WX
	int MouseY;					//�}�E�X���WY
	float Time;					//�������f���̎���
};

