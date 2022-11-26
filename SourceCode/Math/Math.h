#pragma once
#include<DxLib.h>

/// <summary>
/// �x�N�g�����m�̉��Z
/// </summary>
/// <param name="lhs">����(VECTOR)</param>
/// <param name="rhs">�E��(VECTOR)</param>
/// <returns>2�̃x�N�g���̘a</returns>
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g�����m�̌��Z
/// </summary>
/// <param name="lhs">����(VECOTR)</param>
/// <param name="rhs">�E��(VECOTR)</param>
/// <returns>2�̃x�N�g���̍�</returns>
VECTOR operator-(const VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̃X�J���[�{
/// </summary>
/// <param name="lhs">����(VECTOR)</param>
/// <param name="s">�E��(float)</param>
/// <returns>�x�N�g����float���|�����l</returns>
VECTOR operator*(const VECTOR& lhs, float s);

/// <summary>
/// �x�N�g���̉��Z�q
/// </summary>
/// <param name="lhs">����(VECTOR)</param>
/// <param name="rhs">�E��(VECTOR)</param>
/// <returns>���ӂɉE�ӂ����Z�����x�N�g���̒l</returns>
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs);

/// <summary>
/// �x�N�g���̃X�J���[�{�̉��Z�q
/// </summary>
/// <param name="lhs">����(VECTOR)</param>
/// <param name="rhs">�E��(float)</param>
/// <returns>���ӂɉE�ӂ���Z�����x�N�g���̒l</returns>
VECTOR operator*=(VECTOR& lhs, float rhs);
