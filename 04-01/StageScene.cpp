#include "StageScene.h"
#include <Novice.h>


void StageScene::Initialize() {
	player_ = std::make_unique<Player>();
	player_->Initialize();
	enemyX_ = 640;
	enemyY_ = 70;
	enemyRadius_ = 50;
	enemyIsAlive_ = true;
}

void StageScene::Update() {
	player_->Update();

	int length = player_->GetBulletRadius() + enemyRadius_;
	int directionX = player_->GetBulletX() - enemyX_;
	int directionY = player_->GetBulletY() - enemyY_;
	if (length * length > directionX * directionX + directionY * directionY) {
		enemyIsAlive_ = false;
	}

	if(!enemyIsAlive_){
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() {
	player_->Draw();

	if (enemyIsAlive_) {
		Novice::DrawEllipse(enemyX_, enemyY_, enemyRadius_, enemyRadius_, 0.0f, 0xFF0000FF, kFillModeSolid);
	}
}
