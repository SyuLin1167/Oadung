#include"DxLib.h"
#include"SceneManager.h"
#include"ObjManager.h"
#include"AssetManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//---��ʃ��[�h�̃Z�b�g---//
	SetGraphMode(ScreenWidth, ScreenHeight, ColorBit);
	ChangeWindowMode(TRUE);

	//---DX���C�u����������---//
	if (DxLib_Init() == -1)
	{
		return -1;				//�G���[���N������I��
	}

	//�Ǘ��N���X�̏���������//
	ObjManager::Init();
	AssetManager::Init();

	SceneManager* sceneManager = new SceneManager();

	//---�V�[�����[�v---//
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)		//�E�B���h�E�������邩�AESC�L�[���������܂Ŏ��s
	{


		sceneManager->Update();			//�X�V����
		ClearDrawScreen();				//��ʂ�������

		sceneManager->Draw();			//�`�揈��
		ScreenFlip();					//����ʂ̓��e��\�`��ɔ��f
	}
	ObjManager::Finalize();
	AssetManager::Finalize();

	DxLib_End();						//Dx���C�u�����̌㏈��

	return 0;							//�\�t�g�̏I��
}