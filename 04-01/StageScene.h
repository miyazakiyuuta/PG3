#pragma once
#include "IScene.h"
#include <memory>
#include "Player.h"

class StageScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	std::unique_ptr<Player> player_;

	int enemyX_;
	int enemyY_;
	int enemyRadius_;
	int enemyIsAlive_;
};

