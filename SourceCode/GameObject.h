#pragma once
#include<DxLib.h>
#include"Math.h"

/*�e�N���X*/
class GameObject
{
public:
    /// <summary>
    /// �R���X�g���N�^�[
    /// </summary>
    GameObject();

    /// <summary>
    /// �f�X�g���N�^�[
    /// </summary>
    virtual ~GameObject();

    /// <summary>
    /// ���W�擾
    /// </summary>
    /// <returns>�Z�b�g���ꂽ���W</returns>
    const VECTOR& GetPosition()const { return Position; }

    /// <summary>
    /// ���W�ݒ�
    /// </summary>
    /// <param name="setPos">:���W�ɃZ�b�g����l</param>
    void SetPosition(const VECTOR setPos) { Position = setPos; }

    /// <summary>
    /// �����擾
    /// </summary>
    /// <returns>�Z�b�g���ꂽ����</returns>
    const VECTOR& GetDir()const { return Dir; }

    /// <summary>
    /// �����ݒ�
    /// </summary>
    /// <param name="dir">:�����ɃZ�b�g����l</param>
    void SetDir(const VECTOR dir) { Dir = dir; }

    /// <summary>
    /// ��������
    /// </summary>
    /// <returns>�������</returns>
    bool IsAlive() { return isAlive; }

    /// <summary>
    /// �����ݒ�
    /// </summary>
    /// <param name="alive">:�����Ă��邩�ǂ���</param>
    void SetAlive(bool alive) { isAlive = alive; }

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">:�t���[�����[�g</param>
    virtual void Update(float deltaTime) = 0;

    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();

protected:
    VECTOR Position;        //���[���h���W
    VECTOR Dir;             //���[���h����
    int modelHandle;        //���f���n���h��
    bool isAlive;           //�������
};

