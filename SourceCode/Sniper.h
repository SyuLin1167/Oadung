#pragma once
#include <DxLib.h>

/*Sniperのクラス*/
class Sniper
{
public:
	/// <summary>
	/// Sniperコンストラクタ―
	/// </summary>
	Sniper();

	/// <summary>
	/// Sniperデストラクタ―
	/// </summary>
	~Sniper();

	/// <summary>
	/// Sniper更新処理
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Sniper描画処理
	/// </summary>
	void Draw();

private:
	int snpHandle;		//Sniper画像ハンドル
	VECTOR snpPos;		//Sniper座標
};

