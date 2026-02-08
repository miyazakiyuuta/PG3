#pragma once
class Enemy {
public:
	void Update();

private:
	// メンバ関数
	void Approach(); // 接近
	void Fire(); // 射撃
	void Withdrawal(); // 離脱

	// メンバ関数ポインタ
	static void (Enemy::* state[])();

private:
	enum class Phase {
		Approach,
		Fire,
		Withdrawal,
	};

	Phase phase_ = Phase::Approach;
};

