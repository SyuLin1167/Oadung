#pragma once
#include <DxLib.h>



/*Bowのクラス*/
class Bow
{
public:
	/// <summary>
	/// Bowコンストラクタ―
	/// </summary>
	Bow();

	/// <summary>
	/// Bowデストラクタ―
	/// </summary>
	~Bow();

	/// <summary>
	/// Bow更新処理
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Bow描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// Bow死亡判定
	/// </summary>
	/// <returns>死亡フラグ</returns>
	bool IsDead() { return isDead; }

	/// <summary>
	/// Bowモデル削除
	/// </summary>
	static void UnloadModel();

private:
	static int bowHandle;		//Bowモデルハンドル
	int bowDuplicate;			//複製モデル(読み込み不要)
	VECTOR bowPos;				//Bow座標

	bool isDead;				//死亡フラグ

	int MouseX;					//マウス座標X
	int MouseY;					//マウス座標Y
	float Time;					//複製モデルの寿命
};

