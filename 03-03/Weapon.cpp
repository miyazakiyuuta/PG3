#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const char* weaponName) {
	name = weaponName;
}

void Weapon::Attack() {
	printf("%s\n", name);
}