#pragma once
#include <DxLib.h>

/*Sniper�̃N���X*/
class Sniper
{
public:
	/// <summary>
	/// Sniper�R���X�g���N�^�\
	/// </summary>
	Sniper();

	/// <summary>
	/// Sniper�f�X�g���N�^�\
	/// </summary>
	~Sniper();

	/// <summary>
	/// Sniper�X�V����
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Sniper�`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// Sniper���S����
	/// </summary>
	/// <returns>���S�t���O</returns>
	bool IsDead() { return isDead; }

	/// <summary>
	/// ���f���폜
	/// </summary>
	static void UnloadModel();

private:
	int snpHandle;		//Sniper�摜�n���h��
	int snpDuplicate;	//�������f��(�ǂݍ��ݕs�v)
	VECTOR snpPos;		//Sniper���W

	bool isDead;		//���S�t���O

	int MouseX;
	int MouseY;
};

