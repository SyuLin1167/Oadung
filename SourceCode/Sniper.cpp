#include "Sniper.h"

// @brief Sniperコンストラクタ― //

Sniper::Sniper()
	:snpHandle(-1)
	,snpPos(VGet(10,0,10))
{
	snpHandle = MV1LoadModel("SourceCode/Assets/Player/model_Haland.mv1");
}

// @brief Sniperデストラクタ― //

Sniper::~Sniper()
{
	if (snpHandle != -1)
	{
		MV1DeleteModel(snpHandle);
	}
}

// @brief Sniper更新処理 //

void Sniper::Update(float deltaTime)
{
	MV1SetPosition(snpHandle, snpPos);                              //ポジション設定
}

// @brief Sniper描画処理 //

void Sniper::Draw()
{
	MV1DrawModel(snpHandle);
}