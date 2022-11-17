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
	int PlyHandle;		//Player画像ハンドル
	VECTOR PlyPos;		//Player座標
	VECTOR PlyDir;		//Player方向

	VECTOR FRONT = { 0, 0, 1 };		//前方向
	VECTOR BEHIND = { 0, 0, -1 };	//後方向
	VECTOR RIGHT = { 1, 0, 0 };		//右方向
	VECTOR LEFT = { -1, 0, 0 };		//左方向

	bool KeyInput;		//キー入力判定
};

