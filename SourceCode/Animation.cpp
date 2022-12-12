#include "Animation.h"
//#include"AssetManager"

// @brief Animation�R���X�g���N�^�[ //

Animation::Animation(int modelHandle)
    :modelHandle(modelHandle)
    ,nowAnimType(-1)
    ,nowAnimTime(0.0f)
    ,attachedIndex(0)
{
}

// @brief Animation�f�X�g���N�^�[ //

Animation::~Animation()
{
}

// @brief �A�j���[�V�����ǉ����� //

int Animation::AddAnimation(string fileName, float animFps, bool animLoop)
{
    AnimData anim = {};                     //�A�j���[�V�����f�[�^
    anim.animFps = animFps;                 //�t���[�����[�g�͈���������
    anim.isLoop = animLoop;                 //���[�v�Đ��t���O�͈���������

    anim.animHandle;
}