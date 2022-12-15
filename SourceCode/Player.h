#pragma once
#include<DxLib.h>

#include"ObjManager.h"
#include"AssetManager.h"
#include"GameObject.h"
#include"Animation.h"
#include"Collision.h"

class Animation;
class Archer;

/* Player�̃N���X */
class Player :public GameObject
{
	Animation* plyAnim = nullptr;					//�A�j���[�V����
	Archer* archer = nullptr;						//�A�[�`���[
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

	/// <summary>
	/// �����蔻�苅�擾
	/// </summary>
	/// <returns>�����蔻�苅</returns>
	Sphere GetColSphere() { return colSphere; }

	/// <summary>
	/// �A�j���[�V�����X�e�[�^�X
	/// </summary>
	typedef enum Anim
	{
		IDLE = 0,						//�ҋ@
		RUN,							//����
		ATACK							//�U��
	};

private:
	VECTOR UP = { 0, 0, 0.9f };			//�O����
	VECTOR DOWN = { 0, 0, -0.9f };		//�����
	VECTOR RIGHT = { 0.9f, 0, 0 };		//�E����
	VECTOR LEFT = { -0.9f, 0, 0 };		//������

	VECTOR InputVec;					//�����x�N�g��
	bool KeyInput;						//�L�[���͔���

	Sphere colSphere;					//�����蔻�苅

	const float putInterval = 1.0f;
	float putTime = 0.0f;

	Anim animType;						//�A�j���[�V�������
};

