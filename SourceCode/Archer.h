#pragma once
#include <DxLib.h>
#include"GameObject.h"
#include"Collision.h"

/*Archer�̃N���X*/
class Archer :public GameObject
{
	Sphere colSphere;
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

	Sphere GetColSphere();
private:
	int MouseX;					//�}�E�X���WX
	int MouseY;					//�}�E�X���WY
	float Time;					//���f���̎���
};

