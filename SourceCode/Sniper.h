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

	/// <summary>
	/// Sniper死亡判定
	/// </summary>
	/// <returns>死亡フラグ</returns>
	bool IsDead() { return isDead; }

	/// <summary>
	/// モデル削除
	/// </summary>
	static void UnloadModel();

private:
	int snpHandle;		//Sniper画像ハンドル
	int snpDuplicate;	//複製モデル(読み込み不要)
	VECTOR snpPos;		//Sniper座標

	bool isDead;		//死亡フラグ

	int MouseX;
	int MouseY;
};

