#include <stdio.h>
#include <list>

using namespace std;

int main() {
	list<const char*> lst{
		"Tokyo","Yurakucho","Shimbashi","Hamamatsucho","Tamachi","Shinagawa","Osaki","Gotanda","Meguro",
		"Ebisu","Shibuya","Harajuku","Yoyogi","Shinjuku","Shin-Okubo","Takadanobaba","Mejiro","Ikebukuro",
		"Otsuka","Sugamo","Komagome","Tabata","Nippori","Uguisudani","Ueno","Okachimachi","Akihabara","Kanda"
	};

	const char* str = "1970";
	printf("%s\n", str);
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Nippori") { printf("\n"); }
		if (*itr == "Shin-Okubo") { printf("\n"); }
		if (*itr == "Shinagawa") { printf("\n"); }
		printf("%s,", *itr);
	}

	str = "2019";
	printf("\n%s\n", str);
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Nippori") {
			itr = lst.insert(itr, "Nishi-Nippori");
			printf("%s,\n", *itr);
			++itr;
		}
		if (*itr == "Shin-Okubo") { printf("\n"); }
		if (*itr == "Shinagawa") { printf("\n"); }
		printf("%s,", *itr);
	}

	str = "2022";
	printf("\n%s\n", str);
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Nippori") { printf("\n"); }
		if (*itr == "Shin-Okubo") { printf("\n"); }
		if (*itr == "Shinagawa") {
			itr = lst.insert(itr, "Takanawa Gateway");
			printf("%s,\n", *itr);
			++itr;
		}
		printf("%s,", *itr);
	}

}