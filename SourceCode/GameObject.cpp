#include "GameObject.h"

// @brief �R���X�g���N�^�[ //

GameObject::GameObject()
    :Position()
    ,Dir()
    ,modelHandle(-1)
    ,isAlive(true)
{
}

// @brief �f�X�g���N�^�[ //
GameObject::~GameObject()
{
    if (modelHandle != -1)
    {
        MV1DeleteModel(modelHandle);
    }
}

// @brief �`�揈�� //

void GameObject::Draw()
{
}