#include "Enemy.h"
#include"Math.h"

int Enemy::emyHandle = -1;

/* @brief Enemy�R���X�g���N�^ */

Enemy::Enemy()
    :emyPos(VGet(10.0f,0.0f,0.0f))
    ,emyDir(VGet(-1.0f,0.0f,0.0f))
    ,isDead(false)
{
    emyHandle = MV1LoadModel("SourceCode/Assets/Enemy/SampleEnemy.MV1");		//���f���ǂݍ���
    emyDuplicate = MV1DuplicateModel(emyHandle);								//���f������
    MV1SetScale(emyDuplicate, VGet(0.1f, 0.1f, 0.1f));							//���f���̃T�C�Y�ݒ�
    MV1SetPosition(emyDuplicate, emyPos);										//�|�W�V�����ݒ�
}

// @brief Enemy�f�X�g���N�^�[ //

Enemy::~Enemy()
{
    if (emyDuplicate != -1)
    {
        MV1DeleteModel(emyDuplicate);
    }
}

// @brief Enemy�X�V���� //

void Enemy::Update(float deltaTime)
{
    emyPos += emyDir * firstSpeed * deltaTime;                //�ړ�
    MV1SetPosition(emyDuplicate, emyPos);                        //�|�W�V�����ݒ�
    MATRIX RotMatY = MGetRotY(90 * (float)(DX_PI / 90.0f));       //�������ɉ�]������
    MV1SetRotationZYAxis(emyDuplicate, VTransform(emyDir, RotMatY), VGet(0.0f, 1.0f, 0.0f), 0.0f);         //���f����]
}

// @brief Enemy�`�揈�� //

void Enemy::Draw()
{
    MV1DrawModel(emyDuplicate);
}

// @brief Enemy���f���폜 //

void Enemy::UnloadModel()
{
    if (emyHandle != -1)
    {
        MV1DeleteModel(emyHandle);
    }
}

