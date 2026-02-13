#include "Player.h"
#include <Novice.h>

void Player::Initialize() {
	x_ = 640;
	y_ = 540;
	radius_ = 20;
	bulletX_ = 0;
	bulletY_ = 0;
	bulletRadius_ = 10;
	isShot_ = false;
}

void Player::Update() {
		// プレイヤー移動
	if (Novice::CheckHitKey(DIK_W)) {
		y_ -= 5;
	}
	if (Novice::CheckHitKey(DIK_S)) {
		y_ += 5;
	}
	if (Novice::CheckHitKey(DIK_A)) {
		x_ -= 5;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		x_ += 5;
	}
	// 弾発射
	if (Novice::CheckHitKey(DIK_SPACE) && !isShot_) {
		bulletX_ = x_;
		bulletY_ = y_;
		isShot_ = true;
	}
	// 弾移動
	if (isShot_) {
		bulletY_ -= 10;
		if (bulletY_ + bulletRadius_ < 0) {
			isShot_ = false;
		}
	}
}

void Player::Draw() {
	Novice::DrawEllipse(x_, y_, radius_, radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	if (isShot_) {
		Novice::DrawEllipse(bulletX_, bulletY_, bulletRadius_, bulletRadius_, 0.0f, 0xFFFF00FF, kFillModeSolid);
	}
}