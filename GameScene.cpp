#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() { 
	// テクスチャの読み込み
	textureHandle_ = TextureManager::Load("mario.jpg");
	// モデルの生成
	model_ = Model::Create();
	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// カメラの初期化
	camera_.Initialize();
    // ライン描画が参照するカメラを指定する（アドレス渡し）
	PrimitiveDrawer::GetInstance()->SetCamera(&camera_);
	// デバッグカメラの生成
	debugCamera_ = new DebugCamera(1270.0f, 720.0f);
	// 軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	// 軸方向表示が参照するビュープロジェクションを指定する（アドレス渡し）
	AxisIndicator::GetInstance()->SetTargetCamera(&debugCamera_->GetCamera());
}

void GameScene::Update() { 
	debugCamera_->Update(); 
}

void GameScene::Draw() { 
	// 3Dモデル描画前処理
	Model::PreDraw();
	// 3Dモデル描画
	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);
	//3Dモデル描画後処理
	Model::PostDraw();
}

GameScene::~GameScene() {
	delete model_;
	delete debugCamera_;
}

