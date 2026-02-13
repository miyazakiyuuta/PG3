#include <Novice.h>
#include "InputHandler.h"
#include "Player.h"
#include "Command.h"

const char kWindowTitle[] = "LE2B_25_ミヤザキ_ユウタ_PG3_05-01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	InputHandler* inputHandler = new InputHandler();

	inputHandler->AssignMoveLeftCommand2PressKeyA();
	inputHandler->AssignMoveRightCommand2PressKeyD();

	Player* player = new Player();

	ICommand* iCommand = nullptr;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		iCommand = inputHandler->HandleInput();

		if (iCommand != nullptr){
			iCommand->Exec(*player);
		}

		player->Update();

		player->Draw();

		// フレームの終了
		Novice::EndFrame();
	}

	delete player;
	delete inputHandler;


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
