#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA(std::string name, Weapon &weapon);
	void attack() const;
	~HumanA();
};

#endif