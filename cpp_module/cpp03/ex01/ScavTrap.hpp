#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator=(const ScavTrap &origin);
	~ScavTrap();

	void guardGate() const;


};

#endif