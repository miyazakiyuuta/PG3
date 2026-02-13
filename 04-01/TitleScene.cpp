#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Initialize() {
}

void TitleScene::Update() {
	if (Novice::CheckHitKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawBox(630, 350, 20, 20, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}
