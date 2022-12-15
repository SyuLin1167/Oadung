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
	ReleaceAllObj();										//���ׂẴI�u�W�F�N�g���폜
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
		delete objInstance->holdObj.back();					//��������f�[�^�폜
		objInstance->holdObj.pop_back();					//��������v�f�폜
	}

	while (!objInstance->Object.empty())					//�A�N�e�B�u�I�u�W�F�N�g������ɂȂ�܂�
	{
		delete objInstance->Object.back();					//��������f�[�^�폜
		objInstance->Object.pop_back();						//��������v�f�폜
	}
}

// @brief �S�I�u�W�F�N�g�̍X�V���� //

void ObjManager::Update(float deltaTime)
{
	for (auto obj : objInstance->Object)			//���ׂẴA�N�^�[�̍X�V
	{
		obj->Update(deltaTime);								//�Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
	}

	for (auto holding : objInstance->holdObj)		//�ꎞ�ۑ����̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
	{
		objInstance->Object.emplace_back(holding);		//�ۑ����̃I�u�W�F�N�g�f�[�^���I�u�W�F�N�g�ֈړ�
	}
	objInstance->holdObj.clear();							//�S�Ĉڂ��I�������ꎞ�ۑ��I�u�W�F�N�g������ɂ���

	Dead();
}

// @brief �I�u�W�F�N�g�̐����� //

void ObjManager::Dead()
{
	vector<GameObject*>deadObj;										//���S�I�u�W�F�N�g
	for (int i = 0; i < objInstance->Object.size(); i++)			//���S���Ă���I�u�W�F�N�g������
	{
		if (!objInstance->Object[i]->IsAlive())						//�I�u�W�F�N�g�������Ă��Ȃ�������
		{
			deadObj.emplace_back(objInstance->Object[i]);		//���S�I�u�W�F�N�g�ֈړ�

			objInstance->Object.erase(
				remove_if(objInstance->Object.begin(),objInstance->Object.end(),
			 [](GameObject* gObj) {return !gObj->IsAlive(); }),objInstance->Object.cend());
		}
	}

	while (!deadObj.empty())										//���S�I�u�W�F�N�g����ɂȂ�܂�
	{
		delete deadObj.back();										//��������폜
		deadObj.pop_back();											//�����̃f�[�^���폜
	}

}

// @brief �I�u�W�F�N�g�̕`�揈�� //

void ObjManager::Draw()
{
	for (auto obj : objInstance->Object)			//�S�ẴA�N�^�[�̕`��
	{
		obj->Draw();										//�Y���^�O�ɂ���S�ẴI�u�W�F�N�g��`��
	}
}

// @birief ObjManager�̊J�� //

void ObjManager::Finalize()
{
	ReleaceAllObj();										//�S�ẴI�u�W�F�N�g�J��
	if (objInstance)										//objManager�Ɏ��Ԃ���������
	{
		delete objInstance;									//�폜
	}
}