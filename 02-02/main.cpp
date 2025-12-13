#include <stdio.h>

int RecursiveWage(int hours) {
	if (hours == 1) {
		return 100;
	}
	return RecursiveWage(hours - 1) * 2 - 50;
}

int main() {

	int hours = 0;
	int general = 0;
	int recursive = 0;

	while (general >= recursive) {
		hours++;
		printf("%d時間: ", hours);
		general = 1226 * hours;
		printf("一般的=%d円, ", general);
		recursive = RecursiveWage(hours);
		printf("再帰的=%d円\n", recursive);
	}

	return 0;
}