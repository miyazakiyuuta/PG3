#pragma once
#include "Weapon.h"

class Sword : public IWeapon{
public:
	Sword();
	~Sword();
	void Attack() override;
};

