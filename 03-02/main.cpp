#include <iostream>

using namespace std;

template <typename Type1, typename Type2>

class Value {
public:
	Type1 a;
	Type2 b;

	// コンストラクタ
	Value(Type1 a, Type2 b) : a(a), b(b) {}

	// メンバ関数
	Type1 Min() {
		return static_cast<Type1>(a < b ? a : b);
	}
};

int main() {
	Value<int, int> a(3, 5);
	Value<float, float> b(2.5f, 1.2f);
	Value<double, double> c(9.8, 7.7);

	Value<int, float> d(3, 4.5f);
	Value<int, double> e(10, 3.14);
	Value<float, double> f(2.5f, 1.1);

	printf("a(3, 5).Min = %d\n", a.Min());
	printf("b(2.5f, 1.2f).Min = %f\n", b.Min());
	printf("c(9.8, 7.7).Min = %f\n", c.Min());
	printf("d(3, 4.5f).Min = %d\n", d.Min());
	printf("e(10, 3.14).Min = %d\n", e.Min());
	printf("f(2.5f, 1.1).Min = %f", f.Min());

	return 0;
}