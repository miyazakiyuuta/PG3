#include "Gun.h"
#include <iostream>

Gun::Gun() : IWeapon("Shoot a Gun!") {
}

Gun::~Gun() {
}

void Gun::Attack() {
	printf("銃を装備\n");
	IWeapon::Attack();
}
