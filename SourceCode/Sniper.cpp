#include "Sniper.h"

// @brief Sniper�R���X�g���N�^�\ //

Sniper::Sniper()
	:snpHandle(-1)
	,snpPos(VGet(10,0,10))
{
	snpHandle = MV1LoadModel("SourceCode/Assets/Player/model_Haland.mv1");
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
	MV1SetPosition(snpHandle, snpPos);                              //�|�W�V�����ݒ�
}

// @brief Sniper�`�揈�� //

void Sniper::Draw()
{
	MV1DrawModel(snpHandle);
}