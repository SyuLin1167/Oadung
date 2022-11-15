#pragma once
#include"DxLib.h"

const int FirstSpeed = 2;	//初期速度

/*Playerのクラス*/
class Player
{
public:
	/// <summary>
	/// Playerコンストラクター
	/// </summary>
	Player();

	/// <summary>
	/// Playerデストラクター
	/// </summary>
	~Player();

	/// <summary>
	/// Player更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// Player描画処理
	/// </summary>
	void Draw();

private:
	int PlyHandle;			//Player画像ハンドル
	VECTOR PlayerPos;		//Player座標
};

