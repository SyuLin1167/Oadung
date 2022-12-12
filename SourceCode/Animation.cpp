#include "Animation.h"
#include"AssetManager.h"

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

int Animation::AddAnimation(string animFileName, float animFps, bool animLoop)
{
    AnimData anim = {};                     //�A�j���[�V�����f�[�^
    anim.animFps = animFps;                 //�t���[�����[�g�͈���������
    anim.isLoop = animLoop;                 //���[�v�Đ��t���O�͈���������

    anim.animHandle = AssetManager::GetAnim(animFileName.c_str());      //�A�j���[�V�����f�[�^�ǂݍ���
    if (anim.animHandle == -1)                                          //�f�[�^�������Ă��Ȃ�������
    {
        return -1;                                                      //�����Ă��Ȃ��Ƃ������ʂ�Ԃ�
    }

    anim.animIndex = MV1GetAnimNum(anim.animHandle) - 1;                //�A�j���[�V�����̌�����C���f�b�N�X�𓾂�

    attachedIndex = MV1AttachAnim(modelHandle, anim.animIndex,
        anim.animHandle, TRUE);                    //�A�j���[�V���������f���ɒǉ�

    anim.totalTime = MV1GetAnimTotalTime(modelHandle, anim.animIndex);      //�A�j���[�V�����Đ����Ԏ擾


}