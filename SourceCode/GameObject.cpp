#include "GameObject.h"

// @brief �R���X�g���N�^�[ //

GameObject::GameObject(ObjectTag tag)
    :objTag(tag)
    ,objHandle(-1)
    ,objPos(VGet(0.0f,0.0f,0.0f))
    ,objDir(VGet(0.0f,0.0f,0.0f))
    ,objSpeed(0.0f)
    ,isAlive(true)
{
}

// @brief �f�X�g���N�^�[ //
GameObject::~GameObject()
{
    if (objHandle != -1)
    {
        MV1DeleteModel(objHandle);
    }
}

// @brief �`�揈�� //

void GameObject::Draw()
{
}