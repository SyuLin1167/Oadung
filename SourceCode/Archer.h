#pragma once
#include <DxLib.h>
#include"GameObject.h"


/*Archer�̃N���X*/
class Archer :public GameObject
{
public:
	/// <summary>
	/// Archer�R���X�g���N�^�\
	/// </summary>
	Archer();

	/// <summary>
	/// Archer�f�X�g���N�^�\
	/// </summary>
	~Archer();

	/// <summary>
	/// Archer�X�V����
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Archer�`�揈��
	/// </summary>
	void Draw();

private:
	int MouseX;					//�}�E�X���WX
	int MouseY;					//�}�E�X���WY
	float Time;					//���f���̎���
};

