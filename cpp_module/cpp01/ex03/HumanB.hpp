#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon weapon);
	void setWeapon(Weapon weapon);
	void attack();
	~HumanB();
};

#endif