#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("A");
	ClapTrap clap2(clap);

	clap.printStatus();
	clap2.printStatus();

	clap.attack("B");
	clap.takeDamage(10);
	clap.printStatus();

	clap2.takeDamage(45);
	clap2.printStatus();

	clap.beRepaired(10);
	clap.printStatus();

	clap.beRepaired(45);
	clap.printStatus();

	clap2.printStatus();
	
	return 0;
}