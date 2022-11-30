#include "Archer.h"

// @brief Archerコンストラクタ― //

Archer::Archer()
	:GameObject(ObjectTag::Archer)
	,MouseX(0)
	,MouseY(0)
	,Time(0)
{
	objHandle = MV1LoadModel("SourceCode/Assets/Archer/SampleModel.mv1");			//モデル読み込み
	MV1SetScale(objHandle, VGet(0.1f, 0.1f, 0.1f));									//モデルのサイズ設定

	//---マウス座標設定---//
	GetMousePoint(&MouseX, &MouseY);												//マウスの位置を取得
	objPos = VGet(((float)MouseX - 640) / 10, 0.0f, (-(float)MouseY + 512) / 10);	//マウス座標を3D座標に変換(仮)

	MV1SetPosition(objHandle, objPos);												//ポジション設定

	//---当たり判定球設定---//
	colSphere.localCenter = VGet(0, 10, 0);			//ローカル座標
	colSphere.Radius = 5.0f;						//球半径
	colSphere.worldCenter = objPos;					//ワールド座標
}

// @brief Archerデストラクタ― //

Archer::~Archer()
{
	if (objHandle != -1)					//オブジェクトが空でなければ
	{
		MV1DeleteModel(objHandle);			//削除
	}
}

// @brief Archer更新処理 //

void Archer::Update(float deltaTime)
{
	colSphere.Move(objPos);					//当たり判定の移動

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

	//---当たり判定デバッグ描画(後で消す)---//
	DrawSphere3D(colSphere.worldCenter, colSphere.Radius, 8, GetColor(0, 255, 255), 0, FALSE);
}
