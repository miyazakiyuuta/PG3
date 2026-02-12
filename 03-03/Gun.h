#pragma once
#include "Weapon.h"

class Gun : public Weapon{
public:
	Gun();
	~Gun();
	void Attack() override;
};

