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

private:
	int snpHandle;		//Sniper�摜�n���h��
	VECTOR snpPos;		//Sniper���W
};

