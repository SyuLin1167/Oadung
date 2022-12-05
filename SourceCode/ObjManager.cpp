#include "ObjManager.h"
#include"GameObject.h"

ObjManager* ObjManager::objInstance = nullptr;				//ObjManager���̂ւ̃|�C���^��`

// @brief ObjManager�R���X�g���N�^�[ //

ObjManager::ObjManager()
	:Object()
{
	objInstance = nullptr;
}

// @brief ObjManager�f�X�g���N�^�[ //

ObjManager::~ObjManager()
{
	ReleaceAllObj();
}

// @brief ObjManager���������� //

void ObjManager::Init()
{
	if (!objInstance)										//�|�C���^���󂾂�����
	{
		objInstance = new ObjManager;						//�|�C���^������
	}
}

// @brief �I�u�W�F�N�g�o�^ //

void ObjManager::Entry(GameObject*newObj)
{
	objInstance->holdObj.emplace_back(newObj);				//�I�u�W�F�N�g�ꎞ�ۑ�
}

//@brief �I�u�W�F�N�g�폜 //

void ObjManager::Release(GameObject* releaseObj)
{
	auto iter = find(objInstance->holdObj.begin(),
		objInstance->holdObj.end(), releaseObj);			//�ꎞ�ۑ��I�u�W�F�N�g��������

	if (iter != objInstance->holdObj.end())					//�I�u�W�F�N�g������������
	{
		iter_swap(iter, objInstance->holdObj.end() - 1);	//�������I�u�W�F�N�g���Ō���Ɉړ�
		objInstance->holdObj.pop_back();					//�f�[�^���폜

		//objInstance->holdObj.erase(iter);					//-----------------------���̏���������_���Ȃ̂�
		return;
	}

	iter = find(objInstance->Object.begin(),
		objInstance->Object.end(), releaseObj);				//�A�N�e�B�u�I�u�W�F�N�g��������

	if (iter != objInstance->Object.end())					//�I�u�W�F�N�g������������
	{
		iter_swap(iter, objInstance->Object.end() - 1);		//�������I�u�W�F�N�g�𖖔��Ɉړ�
		delete objInstance->Object.back();					//�I�u�W�F�N�g�폜
	}
}

// @brief �S�I�u�W�F�N�g�폜 //

void ObjManager::ReleaceAllObj()
{
	while (!objInstance->holdObj.empty())					//�ꎞ�ۑ��I�u�W�F�N�g������ɂȂ�܂�
	{
		delete objInstance->holdObj.back();					//��������폜	---------������pop_back����Ȃ��̂�
	}

	while (!objInstance->Object.empty())					//�A�N�e�B�u�I�u�W�F�N�g������ɂȂ�܂�
	{
		delete objInstance->Object.back();					//��������폜
		objInstance->Object.pop_back();						//-----------------------�Ȃ����̕����K�v�Ȃ̂�
	}
}

// @brief �S�I�u�W�F�N�g�̍X�V���� //

void ObjManager::Update(float deltaTime)
{
	for (auto obj : objInstance->Object)			//���ׂẴA�N�^�[�̍X�V
	{
		obj->Update(deltaTime);						//�Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
	}

	for (auto holding : objInstance->holdObj)
	{
		objInstance->Object.emplace_back(holding);	//�ꎞ�ۑ����̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
	}
	objInstance->holdObj.clear();

}

// @brief �I�u�W�F�N�g�̐����� //

void ObjManager::Dead()
{
	
}