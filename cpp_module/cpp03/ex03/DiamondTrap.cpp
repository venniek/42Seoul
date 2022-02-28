#include "DiamondTrap.hpp"

void DiamondTrap::printStatus() const {
	std::cout << std::setw(40) << std::setfill('-') << DiamondTrap::_name + "'s status--------------" << std::setfill(' ') << std::endl;
	std::cout << std::setw(25) << "name: " << _name << std::endl;
	std::cout << std::setw(25) << "hit point: " << _hitPoint << std::endl;
	std::cout << std::setw(25) << "energy point: " << _energyPoint << std::endl;
	std::cout << std::setw(25) << "attack damage: " << _attackDamage<< std::endl;
	std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl << std::endl;
	std::setfill('-');
}

DiamondTrap::DiamondTrap() : _name("") {
	ClapTrap::_name = "_clap_name";
	_energyPoint = 20;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"),ScavTrap(name), FragTrap(name), _name(name) {
	this->_energyPoint = 20;
	std::cout << "DiamondTrap constructor with name \"" << _name << "\" called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &origin): ClapTrap(origin) {
	*this = origin;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &origin) {
	ClapTrap::operator=(origin);
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}


void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap name : " << DiamondTrap::_name << std::endl;
	std::cout << "ClapTrap name    : " << ClapTrap::getName() << std::endl;
}