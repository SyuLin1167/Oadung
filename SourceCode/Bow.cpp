#include "Bow.h"

int Bow::bowHandle = -1;

// @brief Bow�R���X�g���N�^�\ //

Bow::Bow()
	:bowPos(VGet(0,0,0))
	,isDead(false)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	bowHandle = MV1LoadModel("SourceCode/Assets/Bow/SampleModel.MV1");			//���f���ǂݍ���
	bowDuplicate = MV1DuplicateModel(bowHandle);									//���f������
	MV1SetScale(bowDuplicate, VGet(0.1f, 0.1f, 0.1f));								//���f���̃T�C�Y�ݒ�
	GetMousePoint(&MouseX, &MouseY);												//�}�E�X�̈ʒu���擾
	bowPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 5);	//�}�E�X���W��3D���W�ɕϊ�(��)
	MV1SetPosition(bowDuplicate, bowPos);											//�|�W�V�����ݒ�
}

// @brief Bow�f�X�g���N�^�\ //

Bow::~Bow()
{
	if (bowDuplicate != -1)
	{
		MV1DeleteModel(bowDuplicate);
	}
}

// @brief Bow�X�V���� //

void Bow::Update(float deltaTime)
{

	Time += deltaTime;
	if (Time >= 3.0f)
	{
		isDead = true;
		Time = 0;
	}
}

// @brief Bow�`�揈�� //

void Bow::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	MV1DrawModel(bowDuplicate);
}

// @brief Bow���f���폜 //

void Bow::UnloadModel()
{
	if (bowHandle != -1)
	{
		MV1DeleteModel(bowHandle);
	}
}