#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamond("diamond");

	diamond.whoAmI();
	std::cout << std::endl;

	diamond.takeDamage(20);
	diamond.printStatus();
	std::cout << std::endl;
	
	diamond.attack("other");
	diamond.printStatus();
	std::cout << std::endl;
	
	diamond.beRepaired(45);
	diamond.printStatus();
	
	return 0;
}