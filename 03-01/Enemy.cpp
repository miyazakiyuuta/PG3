#include "Enemy.h"
#include <iostream>

using namespace std;

void Enemy::Update() {
	size_t index = static_cast<size_t>(phase_);

	(this->*state[index])();
}

void Enemy::Approach() {
	printf("Enemy Approach:接近\n");

	phase_ = Phase::Fire;
}

void Enemy::Fire() {
	printf("Enemy Fire:射撃\n");

	phase_ = Phase::Withdrawal;
}

void Enemy::Withdrawal() {
	printf("Enemy Withdrawal:離脱\n");
}

// staticで宣言したメンバ関数ポインタテーブルの実態
void (Enemy::* Enemy::state[])() = {
	&Enemy::Approach, // 要素番号0
	&Enemy::Fire, // 要素番号1
	&Enemy::Withdrawal // 要素番号2
};