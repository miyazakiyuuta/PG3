#pragma once

class Weapon {
public:
	Weapon(const char* weaponName);
	virtual ~Weapon(){}

	virtual void Attack();

protected:
	const char* name;
};
