#include "Sniper.h"

int Sniper::snpHandle = -1;

// @brief Sniperコンストラクタ― //

Sniper::Sniper()
	:snpPos(VGet(0,0,0))
	,isDead(false)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	snpHandle = MV1LoadModel("SourceCode/Assets/Sniper/SampleModel.MV1");
	snpDuplicate = MV1DuplicateModel(snpHandle);
	MV1SetScale(snpDuplicate, VGet(0.1f, 0.1f, 0.1f));					//モデルのサイズ設定
}

// @brief Sniperデストラクタ― //

Sniper::~Sniper()
{
	if (snpDuplicate != -1)
	{
		MV1DeleteModel(snpDuplicate);
	}
}

// @brief Sniper更新処理 //

void Sniper::Update(float deltaTime)
{
	GetMousePoint(&MouseX, &MouseY);								//マウスの位置を取得
	snpPos = VGet(((float)MouseX-640)/10,0.0f,( - (float)MouseY + 512)/5);
	Time += deltaTime;
	if (Time >= 2.0f)
	{
		isDead = true;
		Time = 0;
	}
	MV1SetPosition(snpDuplicate, snpPos);                              //ポジション設定

}

// @brief Sniper描画処理 //

void Sniper::Draw()
{
	DrawFormatString(0, 100, GetColor(255, 255, 0), "mousepos:%d,%d",MouseX,MouseY);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "snphandle:%d", snpPos.x);
	MV1DrawModel(snpDuplicate);
}

// @brief モデル削除 //

void Sniper::UnloadModel()
{
	if (snpHandle != -1)
	{
		MV1DeleteModel(snpHandle);
	}
}