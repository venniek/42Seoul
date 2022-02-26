#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>
#include <iostream>

class ClapTrap {
private:
	std::string name;
	unsigned int hit;
	unsigned int energy;
	unsigned int attackDamage;

public:
	ClapTrap(std::string name);
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printStatus();
	~ClapTrap();
};

#endif