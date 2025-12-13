#include <stdio.h>

template<typename Type>
Type Min(Type a, Type b) {
	return (a < b) ? a : b;
}

int main() {

	printf("%d\n", Min<int>(3, 5));
	printf("%f\n", Min<float>(4.2f, 3.2f));
	printf("%f\n", Min<double>(3.5, 2.1));

	return 0;
}