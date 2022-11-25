#include "Bow.h"

int Bow::bowHandle = -1;

// @brief Bowコンストラクタ― //

Bow::Bow()
	:bowPos(VGet(0,0,0))
	,isDead(false)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	bowHandle = MV1LoadModel("SourceCode/Assets/Bow/SampleModel.MV1");			//モデル読み込み
	bowDuplicate = MV1DuplicateModel(bowHandle);									//モデル複製
	MV1SetScale(bowDuplicate, VGet(0.1f, 0.1f, 0.1f));								//モデルのサイズ設定
	GetMousePoint(&MouseX, &MouseY);												//マウスの位置を取得
	bowPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 5);	//マウス座標を3D座標に変換(仮)
	MV1SetPosition(bowDuplicate, bowPos);											//ポジション設定
}

// @brief Bowデストラクタ― //

Bow::~Bow()
{
	if (bowDuplicate != -1)
	{
		MV1DeleteModel(bowDuplicate);
	}
}

// @brief Bow更新処理 //

void Bow::Update(float deltaTime)
{

	Time += deltaTime;
	if (Time >= 3.0f)
	{
		isDead = true;
		Time = 0;
	}
}

// @brief Bow描画処理 //

void Bow::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	MV1DrawModel(bowDuplicate);
}

// @brief Bowモデル削除 //

void Bow::UnloadModel()
{
	if (bowHandle != -1)
	{
		MV1DeleteModel(bowHandle);
	}
}