#include "Archer.h"

// @brief Archer�R���X�g���N�^�\ //

Archer::Archer()
	:GameObject(ObjectTag::Archer)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	objHandle = MV1LoadModel("SourceCode/Assets/Archer/SampleModel.MV1");			//���f���ǂݍ���
	MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));									//���f���̃T�C�Y�ݒ�
	GetMousePoint(&MouseX, &MouseY);												//�}�E�X�̈ʒu���擾
	objPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 10);	//�}�E�X���W��3D���W�ɕϊ�(��)
	MV1SetPosition(objHandle, objPos);											//�|�W�V�����ݒ�
}

// @brief Archer�f�X�g���N�^�\ //

Archer::~Archer()
{
	if (objHandle != -1)
	{
		MV1DeleteModel(objHandle);
	}
}

// @brief Archer�X�V���� //

void Archer::Update(float deltaTime)
{

	Time += deltaTime;
	if (Time >= 3.0f)
	{
		SetAlive(false);
		Time = 0;
	}
}

// @brief Archer�`�揈�� //

void Archer::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	MV1DrawModel(objHandle);
}
