#include "Gun.h"
#include <iostream>

Gun::Gun() : Weapon("Shoot a Gun!") {
}

Gun::~Gun() {
}

void Gun::Attack() {
	printf("銃を装備\n");
	Weapon::Attack();
}
