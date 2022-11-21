#include "TimeManager.h"

// @brief TimeManager�R���X�g���N�^�\ //

TimeManager::TimeManager()
	:nowTime(0)
	, prevTime(0)
	, deltaTime(0)
{}

// @brief Time�X�V���� //

void TimeManager::Update()
{
	//---�t���[�����[�g�̎Z�o---//
	nowTime = (float)GetNowCount();						//���݂̎������擾
	deltaTime = (nowTime - prevTime) / 1000.0f;		//�t���[�����[�g�̎Z�o
	prevTime = nowTime;								//�ߋ��̎��ԂɌ��݂̎��Ԃ���
}

// @brief TimeManager�f�X�g���N�^�\ //

TimeManager::~TimeManager()
{
}
