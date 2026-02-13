#include "Sword.h"
#include <iostream>

Sword::Sword() : IWeapon("SwordAttack!") {
}

Sword::~Sword() {
}

void Sword::Attack() {
	printf("剣を装備\n");
	IWeapon::Attack();
}
