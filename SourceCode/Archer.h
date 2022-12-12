#pragma once
#include <DxLib.h>
#include"GameObject.h"
#include"Collision.h"

/* Archer�̃N���X */
class Archer :public GameObject
{
public:
	/// <summary>
	/// Archer�R���X�g���N�^�\
	/// </summary>
	Archer(class Player* player);

	/// <summary>
	/// Archer�f�X�g���N�^�\
	/// </summary>
	~Archer();

	/// <summary>
	/// Archer�X�V����
	/// </summary>
	/// <param name="deltaTime">:�t���[�����[�g</param>
	void Update(float deltaTime);

	/// <summary>
	/// Archer�`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �����蔻�苅�擾
	/// </summary>
	/// <returns>�����蔻�苅</returns>
	Sphere GetColSphere() { return colSphere; }

private:
	int MouseX;					//�}�E�X���WX
	int MouseY;					//�}�E�X���WY
	float Time;					//���f���̎���

	Sphere colSphere;			//�����蔻�苅
};

