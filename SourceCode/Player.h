#pragma once
#include<DxLib.h>

const float FirstSpeed = 5.0f;	//初期速度

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
	void Update(float deltaTime);

	/// <summary>
	/// Player描画処理
	/// </summary>
	void Draw();

private:
	int plyHandle;		//Playerモデルハンドル
	VECTOR plyPos;		//Player座標
	VECTOR plyDir;		//Player方向

	VECTOR UP = { 0, 0, 0.9f };			//前方向
	VECTOR DOWN = { 0, 0, -0.9f };		//後方向
	VECTOR RIGHT = { 0.9f, 0, 0 };		//右方向
	VECTOR LEFT = { -0.9f, 0, 0 };		//左方向

	VECTOR InputVec;	//合成ベクトル
	bool KeyInput;		//キー入力判定
};

