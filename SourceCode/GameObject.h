#pragma once
#include<DxLib.h>
#include"Math.h"
#include"ObjectTag.h"

/*�e�N���X*/
class GameObject
{
public:
    /// <summary>
    /// �R���X�g���N�^�\
    /// </summary>
    /// <param name="tag">:�^�O</param>
    GameObject(ObjectTag tag);

    /// <summary>
    /// �f�X�g���N�^�[
    /// </summary>
    virtual ~GameObject();

    /// <summary>
    /// ���W�擾
    /// </summary>
    /// <returns>�Z�b�g���ꂽ���W</returns>
    const VECTOR& GetPosition()const { return objPos; }

    /// <summary>
    /// ���W�ݒ�
    /// </summary>
    /// <param name="setPos">:���W�ɃZ�b�g����l</param>
    void SetPosition(const VECTOR setPos) { objPos = setPos; }

    /// <summary>
    /// �����擾
    /// </summary>
    /// <returns>�Z�b�g���ꂽ����</returns>
    const VECTOR& GetDir()const { return objDir; }

    /// <summary>
    /// �����ݒ�
    /// </summary>
    /// <param name="dir">:�����ɃZ�b�g����l</param>
    void SetDir(const VECTOR dir) { objDir = dir; }

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
    ObjectTag objTag;       //�I�u�W�F�N�g�̎��
    int objHandle;        //���f���n���h��
    VECTOR objPos;          //���[���h���W
    VECTOR objDir;             //���[���h����

    float objSpeed;

    bool isAlive;           //�������
};

