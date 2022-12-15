#include "Archer.h"

#include"Player.h"

// @brief Archer�R���X�g���N�^�\ //

Archer::Archer(Player* player)
	:GameObject(ObjectTag::Archer)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	objHandle = AssetManager::GetMesh("SourceCode/Assets/Archer/SampleModel.mv1");			//���f���ǂݍ���
	MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));									//���f���̃T�C�Y�ݒ�

	//---�}�E�X���W�ݒ�---//
	GetMousePoint(&MouseX, &MouseY);												//�}�E�X�̈ʒu���擾
	objPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 10);	//�}�E�X���W��3D���W�ɕϊ�(��)

	MV1SetPosition(objHandle, objPos);												//�|�W�V�����ݒ�

	//---�����蔻�苅�ݒ�---//
	colSphere.localCenter = VGet(0, 10, 0);			//���[�J�����W
	colSphere.Radius = 5.0f;						//�����a
	colSphere.worldCenter = objPos;					//���[���h���W
}

// @brief Archer�f�X�g���N�^�\ //

Archer::~Archer()
{
	if (objHandle != -1)					//�I�u�W�F�N�g����łȂ����
	{
		MV1DeleteModel(objHandle);			//�폜
	}
}

// @brief Archer�X�V���� //

void Archer::Update(float deltaTime)
{
	colSphere.Move(objPos);					//�����蔻��̈ړ�
}

// @brief Archer�`�揈�� //

void Archer::Draw()
{
	if (isAlive)
	{
		MV1DrawModel(objHandle);

		//---�����蔻��f�o�b�O�`��(��ŏ���)---//
		DrawSphere3D(colSphere.worldCenter, colSphere.Radius, 8, GetColor(0, 255, 255), 0, FALSE);
	}
}
