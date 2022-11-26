#include "Archer.h"

// @brief Archerコンストラクタ― //

Archer::Archer()
	:GameObject(ObjectTag::Archer)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	objHandle = MV1LoadModel("SourceCode/Assets/Archer/SampleModel.MV1");			//モデル読み込み
	MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));									//モデルのサイズ設定
	GetMousePoint(&MouseX, &MouseY);												//マウスの位置を取得
	objPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 10);	//マウス座標を3D座標に変換(仮)
	MV1SetPosition(objHandle, objPos);											//ポジション設定
}

// @brief Archerデストラクタ― //

Archer::~Archer()
{
	if (objHandle != -1)
	{
		MV1DeleteModel(objHandle);
	}
}

// @brief Archer更新処理 //

void Archer::Update(float deltaTime)
{

	Time += deltaTime;
	if (Time >= 3.0f)
	{
		SetAlive(false);
		Time = 0;
	}
}

// @brief Archer描画処理 //

void Archer::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	MV1DrawModel(objHandle);
}
