#include "DiamondTrap.hpp"

int main() {
	ClapTrap clap("clap");
	DiamondTrap diamond("diamond");

	// diamond.whoAmI();
	std::cout << diamond.getEp() << std::endl;
	// clap.printStatus();
	diamond.printStatus();
	// std::cout << std::endl;

	// clap.attack(diamond.getName());
	// clap.printStatus();
	// diamond.takeDamage(clap.getAd());
	// diamond.printStatus();
	// std::cout << std::endl;
	
	// diamond.attack(clap.getName());
	// diamond.printStatus();
	// clap.takeDamage(diamond.getAd());
	// clap.printStatus();
	// std::cout << std::endl;
	
	// clap.beRepaired(10);
	// clap.printStatus();
	// std::cout << std::endl;
	
	// diamond.beRepaired(45);
	// diamond.printStatus();
	
	return 0;
}