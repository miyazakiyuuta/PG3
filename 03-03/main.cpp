
#include "Weapon.h"
#include "Sword.h"
#include "Gun.h"

int main() {
	Weapon* weapons[3];
	for(int i = 0; i < 3; ++i) {
		if(i % 2 == 0) {
			weapons[i] = new Sword();
		} else {
			weapons[i] = new Gun();
		}
	}

	for(auto weapon : weapons) {
		weapon->Attack();
	}

	for(auto weapon : weapons) {
		delete weapon;
	}

	return 0;
}