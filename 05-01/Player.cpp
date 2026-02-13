#include "Player.h"
#include <Novice.h>

Player::Player() {
	x_ = 640;
	y_ = 360;
	width_ = 50;
	height_ = 50;
	speed_ = 5;
}

void Player::Update() {

}

void Player::Draw() {
	Novice::DrawBox(x_ - width_ / 2, y_ - height_ / 2, width_, height_, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() {
	x_ += speed_;
}

void Player::MoveLeft() {
	x_ -= speed_;
}