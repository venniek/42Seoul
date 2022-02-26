#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hit(10), energy(10), attackDamage(0) {
	std::cout << this->name << " start!!" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << name << " is attacked! " << amount << " of damages!" << std::endl;
	energy -= std::min(amount, energy);
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << name << "is repaired... Got " << amount << " of energy..." << std::endl;
	energy += amount;
}

void ClapTrap::printStatus() {
	std::cout << "name         : " << name << std::endl;
	std::cout << "hit          : " << hit << std::endl;
	std::cout << "energy       : " << energy << std::endl;
	std::cout << "attack damage: " << attackDamage << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " destroyed" << std::endl;
}