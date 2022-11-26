#pragma once
#include<DxLib.h>
#include"Math.h"
#include"GameObject.h"


/*Playerのクラス*/
class Player :public GameObject
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
	/// <param name="deltaTime">:フレームレート</param>
	void Update(float deltaTime) override;

	/// <summary>
	/// Player描画処理
	/// </summary>
	void Draw() override;

private:
	VECTOR UP = { 0, 0, 0.9f };			//前方向
	VECTOR DOWN = { 0, 0, -0.9f };		//後方向
	VECTOR RIGHT = { 0.9f, 0, 0 };		//右方向
	VECTOR LEFT = { -0.9f, 0, 0 };		//左方向

	VECTOR InputVec;	//合成ベクトル
	bool KeyInput;		//キー入力判定
};

