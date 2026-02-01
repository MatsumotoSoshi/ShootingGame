#pragma once
#include "KamataEngine.h"

// ゲームシーン
class GameScene 
{
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();
	
	// 描画
	void Draw();

	~GameScene();
	
	// デバッグカメラ
	KamataEngine::Model* model_ = nullptr;
	//ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	// カメラ
	KamataEngine::Camera camera_;
	// デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	
};
