#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef bool (*JudgeFn)(int roll);

bool JudgeOdd(int roll) {
	if (roll % 2 == 1) {
		return true;
	}
	return false;
}

void ShowResult(int roll, int userGuess) {
	JudgeFn judgeFn = JudgeOdd;
	if ((judgeFn(roll) == judgeFn(userGuess))) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
	printf("出た目は%dでした\n", roll);
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	fn = ShowResult;
	// 指定されたミリ秒だけ待機
	Sleep(delayMs);
	// 結果を表示
	fn(roll, userGuess);
}

int main() {
	srand((unsigned int)time(NULL));

	char input{};

	// サイコロを振る
	int roll = rand() % 6 + 1;

	while (true) {
		printf("半(奇数)ならo,丁(偶数)ならe\n");
		scanf("%c", &input, 1);
		if (input == 'o') {
			break;
		} else if (input == 'e') {
			break;
		} else {
			printf("もう一度入力したまえ\n");
		}
	}

	int userGuess = (input == 'o') ? 1 : 0; // oなら1,そうでない(つまりe)なら0

	DelayReveal(ShowResult, 3000, roll, userGuess);

	clock_t start_time = clock();
	while (clock() - start_time < 3000 * (CLOCKS_PER_SEC / 1000));

	return 0;
}