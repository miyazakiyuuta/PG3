#pragma once
#include "Weapon.h"

class Gun : public IWeapon{
public:
	Gun();
	~Gun();
	void Attack() override;
};

