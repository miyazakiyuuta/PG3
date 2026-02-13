#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize() {
}

void ClearScene::Update() {
	if(Novice::CheckHitKey(DIK_RETURN)){
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(630, 350, 20, 20, 0.0f, 0xFFFF00FF, kFillModeSolid);
}
