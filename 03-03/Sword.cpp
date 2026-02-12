#include "Sword.h"
#include <iostream>

Sword::Sword() : Weapon("SwordAttack!") {
}

Sword::~Sword() {
}

void Sword::Attack() {
	printf("剣を装備\n");
	Weapon::Attack();
}
