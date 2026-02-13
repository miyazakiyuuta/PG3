#pragma once
class Player {
public:
	Player();

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:
	int x_;
	int y_;
	int width_;
	int height_;
	int speed_;
};

