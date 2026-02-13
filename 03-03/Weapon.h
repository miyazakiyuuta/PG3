#pragma once

class IWeapon {
public:
	IWeapon(const char* weaponName);
	virtual ~IWeapon(){}

	virtual void Attack() = 0;

protected:
	const char* name;
};
