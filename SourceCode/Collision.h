#pragma once
#include<DxLib.h>
#include"Math/Math.h"

/*���̂̍\����*/
struct Sphere
{
    /// <summary>
    /// Sphere�R���X�g���N�^�[
    /// </summary>
    Sphere();

    /// <summary>
    /// Sphere�R���X�g���N�^�[(�����t)
    /// </summary>
    /// <param name="center">���S���W</param>
    /// <param name="radius">���a</param>
    Sphere(const VECTOR& center, float radius);

    /// <summary>
    /// Sphere���쏈��
    /// </summary>
    /// <param name="pos">���̂̃��[���h���W</param>
    void Move(const VECTOR& pos);

    VECTOR localCenter;     //���̂̃��[�J�����S���W
    VECTOR worldCenter;     //���̂̃��[���h���S���W
    float Radius;          //���̂̔��a
};

/// <summary>
/// ���̓��m�̓����蔻��
/// </summary>
/// <param name="sphere1">����1</param>
/// <param name="sphere2">����2</param>
/// <returns>�Ԃ����Ă��邩�ǂ���</returns>
bool CollisionPair(const Sphere & sphere1, const Sphere & sphere2);

