#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <chrono>
#include <thread>

int main() {
	srand((unsigned int)time(NULL));

	// ラムダ式

	// bool JudgeOdd(int roll)
	std::function<bool(int)> judgeOdd = [](int roll) {
		return (roll % 2) == 1;
		};

	// void Sleep(unsigned int ms)
	std::function<void(unsigned int)> sleepMs = [](unsigned int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		};

	// void ShowResult(int roll, int userGuess)
	std::function<void(int, int)> showResult =
		[&](int roll, int userGuess) -> void {
		if (judgeOdd(roll) == judgeOdd(userGuess)) {
			printf("正解\n");
		} else {
			printf("不正解\n");
		}
		printf("出た目は%dでした\n", roll);
		};

	// void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess)
	std::function<void(
		std::function<void(int, int)>,
		unsigned int,
		int,
		int)> delayReveal =
		[&](std::function<void(int, int)> fn,
			unsigned int delayMs,
			int roll,
			int userGuess) -> void {

				sleepMs(delayMs);
				fn(roll, userGuess);
		};


	char input{};

	// サイコロを振る
	int roll = rand() % 6 + 1;

	while (true) {
		printf("半(奇数)ならo,丁(偶数)ならe\n");

		scanf(" %c", &input);

		if (input == 'o' || input == 'e') {
			break;
		} else {
			printf("もう一度入力したまえ\n");
		}
	}

	int userGuess = (input == 'o') ? 1 : 0; // oなら1,そうでない(つまりe)なら0

	//DelayReveal(ShowResult, 3000, roll, userGuess);
	delayReveal(showResult, 3000, roll, userGuess);

	return 0;
}