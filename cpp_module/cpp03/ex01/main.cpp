#include "ScavTrap.hpp"

int main() {
	ClapTrap clap("naykim");

	clap.printStatus();
	clap.attack("mikyan");
	clap.beRepaired(10);
	clap.printStatus();
	clap.beRepaired(45);
	clap.printStatus();
	clap.takeDamage(10);
	clap.printStatus();
	clap.takeDamage(45);
	clap.printStatus();
	
	return 0;
}