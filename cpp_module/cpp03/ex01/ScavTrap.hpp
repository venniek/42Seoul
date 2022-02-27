#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap: ClapTrap {
public:
	ScavTrap(std::string name);
	void guardGate();
	~ScavTrap();
};

#endif