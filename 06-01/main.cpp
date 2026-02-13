#include <stdio.h>
#include <thread>

void Print(int num) {
	printf("thread%d\n", num);
}

int main() {

	std::thread th1(Print, 1);
	th1.join();
	std::thread th2(Print, 2);
	th2.join();
	std::thread th3(Print, 3);
	th3.join();

	return 0;
}