#include"DxLib.h"
#include"SceneManager.h"
#include"TimeManager.h"
#include"Sniper.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//---画面モードのセット---//
	SetGraphMode(ScreenWidth, ScreenHeight, ColorBit);
	ChangeWindowMode(TRUE);

	//---DXライブラリ初期化---//
	if (DxLib_Init() == -1)
	{
		return -1;				//エラーが起きたら終了
	}

	SceneManager* sceneManager = new SceneManager();

	//---シーンループ---//
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)		//ウィンドウが閉じられるか、ESCキーが押されるまで実行
	{


		sceneManager->Update();			//更新処理
		ClearDrawScreen();				//画面を初期化

		sceneManager->Draw();			//描画処理
		ScreenFlip();					//裏画面の内容を表描画に反映
	}
	Sniper::UnloadModel();

	DxLib_End();						//Dxライブラリの後処理

	return 0;							//ソフトの終了
}