#include "Collision.h"

// @brief Sphere�R���X�g���N�^�[ //

Sphere::Sphere()
    :localCenter()
    ,worldCenter()
    ,Radius(0.0f)
{
}

// @brief Sphere�R���X�g���N�^�[(�����t)

Sphere::Sphere(const VECTOR& center,float radius)
    :localCenter(center)
    ,worldCenter(center)
    ,Radius(radius)
{
}

// @brief Sphere���쏈�� //
void Sphere::Move(const VECTOR& pos)
{
    worldCenter = localCenter + pos;
}

// @brief ���̓��m�̓����蔻�� //

bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2)
{
    return HitCheck_Sphere_Sphere(sphere1.worldCenter, sphere1.Radius,
        sphere2.worldCenter, sphere2.Radius);
}