#pragma once

#include<DxLib.h>
#include<string>
#include<unordered_map>

using namespace std;

/*AnimManager�̃N���X*/
class AnimManager
{
public:
	/// <summary>
	/// AnimManager�̃R���X�g���N�^�\
	/// </summary>
	AnimManager();

	/// <summary>
	/// AnimManager�̃f�X�g���N�^�\
	/// </summary>
	~AnimManager();

	/// <summary>
	/// �A�j���[�V�����Z�b�g����
	/// </summary>
	/// <param name="fileName">:�t�@�C����</param>
	/// <param name="animFps">:�Đ��t���[�����[�g</param>
	/// <param name="animLoop">:���[�v�Đ�</param>
	/// <returns></returns>
	int AddAnimation(string fileName, float animFps = 30.0f, bool animLoop = true);

	/// <summary>
	/// �A�j���[�V�������ԃZ�b�g
	/// </summary>
	/// <param name="deltaTime">:�t���[�����[�g</param>
	void AddAnimTime(float deltaTime);

	/// <summary>
	/// �A�j���[�V�����Đ�
	/// </summary>
	/// <param name="animId">:�A�j���[�V����ID</param>
	void StartAnim(int animId);

	/// <summary>
	/// �A�j���[�V������~
	/// </summary>
	void StopAnim();

	/// <summary>
	/// �Đ������ǂ���
	/// </summary>
	/// <returns>�Đ����</returns>
	bool IsPlaying();

	/* �A�j���[�V�����P���̃f�[�^�\���� */
	struct AnimData
	{
		int animHandle;			//�A�j���[�V�����n���h��
		int animIndex;			//�A�^�b�`����A�j���[�V�����ԍ�
		float totalTime;		//���Đ�����
		float animFps;			//�Đ����x
		bool isLoop;			//���[�v�Đ����邩�ǂ���
	};
private:
	int modelHandle;			//���f���n���h��
	vector<AnimData> animData;	//�A�j���[�V���������o�^�p
	int nowAnimType;			//���݂̃A�j���[�V����ID
	int attachedIndex;			//�A�^�b�`��̃C���f�b�N�X
	float nowAnimTime;			//���݂̃A�j���[�V��������
};

