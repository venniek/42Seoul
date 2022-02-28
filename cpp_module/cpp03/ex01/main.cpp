#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("clap");
	ScavTrap scav("scav");

	clap.printStatus();
	scav.printStatus();
	std::cout << std::endl;

	clap.attack(scav.getName());
	clap.printStatus();
	scav.takeDamage(clap.getAd());
	scav.printStatus();
	std::cout << std::endl;
	
	scav.attack(clap.getName());
	scav.printStatus();
	clap.takeDamage(scav.getAd());
	clap.printStatus();
	std::cout << std::endl;
	
	clap.beRepaired(10);
	clap.printStatus();
	std::cout << std::endl;
	
	scav.beRepaired(45);
	scav.printStatus();
	
	return 0;
}