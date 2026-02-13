#include <Novice.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <atomic>
#include <cassert>

std::vector<std::vector<int>> g_mapData;
std::mutex g_mapMutex;           // データの書き込み・読み出しを保護
std::atomic<bool> g_isLoaded(false); // 読み込み完了を知らせるフラグ

void LoadCSV() {
	// ファイルを開く
	std::ifstream file("mapChip_hart.csv");
	assert(file.is_open());

	std::vector<std::vector<int>> temporaryMap;

	std::string line;

	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string value;
		while (std::getline(ss, value, ',')) {
			if (value.empty()) {
				row.push_back(0);
			} else {
				row.push_back(std::stoi(value));
			}
		}
		temporaryMap.push_back(row);

		// 読み込み負荷をシミュレート（実際は不要）
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	// 読み終わったらメインに渡す
	{
		std::lock_guard<std::mutex> lock(g_mapMutex);
		g_mapData = std::move(temporaryMap);
	}
	g_isLoaded = true; // 完了フラグを立てる
}

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	Novice::Initialize("LE2B_25_ミヤザキ_ユウタ_PG3_06-01", 1280, 720);

	std::thread loaderThread(LoadCSV);

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		if(g_isLoaded) {
			std::lock_guard<std::mutex> lock(g_mapMutex);
			
			for (int i = 0; i < g_mapData.size(); i++) {
				for (int j = 0; j < g_mapData[i].size(); j++) {
					if (g_mapData[i][j] == 1) {
						Novice::DrawBox(20 * j, 20 * i, 20, 20, 0.0f, 0xFFFFFFFF, kFillModeSolid);
					}
				}
			}
		}

		Novice::EndFrame();
		if (Novice::CheckHitKey(DIK_ESCAPE)) {
			break;
		}
	}

	if (loaderThread.joinable()) {
		loaderThread.join();
	}

	Novice::Finalize();
	return 0;
}
