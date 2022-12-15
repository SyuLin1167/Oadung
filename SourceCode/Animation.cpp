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
    AnimData anim = {};                                                                     //�A�j���[�V�����f�[�^
    anim.animFps = animFps;                                                                 //�t���[�����[�g�͈���������
    anim.isLoop = animLoop;                                                                 //���[�v�Đ��t���O�͈���������

    anim.animHandle = AssetManager::GetAnim(animFileName.c_str());                          //�A�j���[�V�����f�[�^�ǂݍ���
    if (anim.animHandle == -1)                                                              //�f�[�^�������Ă��Ȃ�������
    {
        return -1;                                                                          //�����Ă��Ȃ��Ƃ������ʂ�Ԃ�
    }

    anim.animIndex = MV1GetAnimNum(anim.animHandle) - 1;                                    //�A�j���[�V�����̌�����C���f�b�N�X�𓾂�

    attachedIndex = MV1AttachAnim(modelHandle, anim.animIndex,
        anim.animHandle, TRUE);                                          //�A�j���[�V���������f���ɒǉ�

    anim.totalTime = MV1GetAnimTotalTime(modelHandle, anim.animIndex);                //�A�j���[�V�����Đ����Ԏ擾

    animData.push_back(anim);                                                           //�����ɃA�j���[�V�����f�[�^�ǉ�

    return static_cast<int>(animData.size());                                               //vector�ɓ���Y�����ԍ���Ԃ�
}

// @brief �A�j���[�V�������ԃZ�b�g //

void Animation::AddAnimTime(float deltaTime)
{
    nowAnimTime += animData[nowAnimType].animFps * deltaTime;                               //���ݎ��ԂɌ��݂̃A�j���[�V�����t���[�������Z

    if (animData[nowAnimType].isLoop && 
        nowAnimTime > animData[nowAnimType].totalTime)                                      //���ݎ��Ԃ��A�j���[�V�����̑��Đ����𒴂��ă��[�v�Đ�������Ȃ�
    {
        nowAnimTime = 0.0f;                                                                 //���ԃ��Z�b�g
    }
}

// @brief �A�j���[�V�����Đ� //

void Animation::StartAnim(int animID)
{
    if (animID != nowAnimType)                                                              //�ȑO�̃A�j���[�V�����ƈ���Ă�����
    {
        if (nowAnimType != -1)                                                              //���݂̃A�j���[�V�������󂶂�Ȃ�������
        {
            MV1DetachAnim(modelHandle, attachedIndex);                      //�f�^�b�`
        }

        nowAnimType = animID;                                                               //�ȑO�̃A�j���[�V�����Ƃ���
        attachedIndex = MV1AttachAnim(modelHandle, animData[animID].animIndex,
            animData[animID].animHandle, TRUE);                          //�A�j���[�V�������A�^�b�`
    }

    nowAnimTime = 0.0f;                                                                     //���ԃ��Z�b�g
    MV1SetAttachAnimTime(modelHandle, attachedIndex, nowAnimTime);          //�A�^�b�`���Ă���A�j���[�V�����̎��Ԑݒ�
}

// @brief �A�j���[�V������~ //

void Animation::StopAnim()
{
    nowAnimTime = animData[nowAnimType].totalTime;                                          //�A�j���[�V���������𑍍Đ����Ԃɂ���
}

// @brief �Đ������ǂ��� //

bool Animation::IsPlaying()
{
    if (animData[nowAnimType].isLoop && nowAnimTime > animData[nowAnimType].totalTime)      //���[�v�Đ��\�ŁA���������Đ����Ԃ𒴂�����
    {
        return false;                                                                       //�Đ����łȂ�false��Ԃ�
    }
    return true;                                                                            //��{�͍Đ�����true��Ԃ�
}





