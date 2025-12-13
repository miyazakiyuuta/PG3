#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool JudgeOdd(int roll) {
	if (roll % 2 == 1) {
		return true;
	}
	return false;
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {

}

typedef bool (*JudgeFn)(int roll);

int main() {
	srand((unsigned int)time(NULL));

	char input{};
	
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

	int roll = rand() % 6 + 1;

	JudgeFn judgeFn = JudgeOdd;

	if (input == 'o') {
		
	}

	return 0;
}