#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

#define S_HITPOINT 100
#define S_ENERGYPOINT 50
#define S_ATTACKDAMAGE 20

class ScavTrap: public ClapTrap {
private:
	bool _guardMode;
public:
	void guardGate() const;
	void printStatus() const;
	void attack(std::string const &target);
	void beRepaired(unsigned int amount);

	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator=(const ScavTrap &origin);
	~ScavTrap();


};

#endif