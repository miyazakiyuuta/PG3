#pragma once
class Player {
public:
	void Initialize();
	void Update();
	void Draw();

	int GetBulletX() { return bulletX_; }
	int GetBulletY() { return bulletY_; }
	int GetBulletRadius() { return bulletRadius_; }

private:
	int x_;
	int y_;
	int radius_;

	int bulletX_;
	int bulletY_;
	int bulletRadius_;
	int isShot_;
};

