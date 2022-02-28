#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	_name = name;
	_hit = 100;
	_ep = 50;
	_ad = 20;
	_initHit = _hit;
	std::cout << "ScavTrap " << _name << " start!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origin): ClapTrap(origin) {
	*this = origin;
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap [GATE KEEPER MODE] start" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &origin) {

}
