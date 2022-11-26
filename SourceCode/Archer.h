#pragma once
#include <DxLib.h>
#include"GameObject.h"


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

private:
	int MouseX;					//マウス座標X
	int MouseY;					//マウス座標Y
	float Time;					//モデルの寿命
};

