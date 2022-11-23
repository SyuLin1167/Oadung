#include "Sniper.h"

// @brief Sniper�R���X�g���N�^�\ //

Sniper::Sniper()
	:snpHandle(-1)
	,snpPos(VGet(0,0,0))
	,isDead(false)
{
	snpHandle = MV1LoadModel("SourceCode/Assets/Sniper/SampleModel.MV1");
}

// @brief Sniper�f�X�g���N�^�\ //

Sniper::~Sniper()
{
	if (snpHandle != -1)
	{
		MV1DeleteModel(snpHandle);
	}
}

// @brief Sniper�X�V���� //

void Sniper::Update(float deltaTime)
{
	GetMousePoint(&MouseX, &MouseY);								//�}�E�X�̈ʒu���擾
	snpPos = VGet((float)MouseX-640,0.0f,-(float)MouseY+512);
	MV1SetPosition(snpHandle, snpPos);                              //�|�W�V�����ݒ�
	MV1SetScale(snpHandle, VGet(0.1f, 0.1f, 0.1f));					//���f���̃T�C�Y�ݒ�

}

// @brief Sniper�`�揈�� //

void Sniper::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "snphandle:%d", snpPos.x);
	MV1DrawModel(snpHandle);
}