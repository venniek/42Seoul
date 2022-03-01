#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap name : " << name << std::endl;
	std::cout << "ClapTrap name    : " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStatus() const {
	std::cout << std::setw(40) << std::setfill('-') << name + "'s status--------------" << std::setfill(' ') << std::endl;
	std::cout << std::setw(25) << "name: " << name << std::endl;
	std::cout << std::setw(25) << "hit point: " << _hitPoint << std::endl;
	std::cout << std::setw(25) << "energy point: " << _energyPoint << std::endl;
	std::cout << std::setw(25) << "attack damage: " << _attackDamage<< std::endl;
	whoAmI();
	std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::endl;
	std::setfill('-');
}

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), name("") {
	_hitPoint = F_HITPOINT;
	_energyPoint = S_ENERGYPOINT;
	_attackDamage = F_ATTACKDAMAGE;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) {
	this->name = name;
	ClapTrap::_name = name + "_clap_name";

	_hitPoint = F_HITPOINT;
	_energyPoint = S_ENERGYPOINT;
	_attackDamage = F_ATTACKDAMAGE;
	std::cout << "DiamondTrap constructor with name \"" << _name << "\" called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &origin): ClapTrap(origin) {
	*this = origin;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &origin) {
	ScavTrap::operator=(origin);
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

