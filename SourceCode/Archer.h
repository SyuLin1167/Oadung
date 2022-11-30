#pragma once
#include <DxLib.h>
#include"GameObject.h"
#include"Collision.h"

/*Archerのクラス*/
class Archer :public GameObject
{
public:
	/// <summary>
	/// Archerコンストラクタ―
	/// </summary>
	Archer();

	/// <summary>
	/// Archerデストラクタ―
	/// </summary>
	~Archer();

	/// <summary>
	/// Archer更新処理
	/// </summary>
	void Update(float deltaTime);

	/// <summary>
	/// Archer描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 当たり判定球取得
	/// </summary>
	/// <returns>当たり判定球</returns>
	Sphere GetColSphere() { return colSphere; }

private:
	int MouseX;					//マウス座標X
	int MouseY;					//マウス座標Y
	float Time;					//モデルの寿命

	Sphere colSphere;			//当たり判定球
};

