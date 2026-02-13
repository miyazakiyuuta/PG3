#include "Weapon.h"
#include <iostream>

IWeapon::IWeapon(const char* weaponName) {
	name = weaponName;
}

void IWeapon::Attack() {
	printf("%s\n", name);
}