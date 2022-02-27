#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("A");
	ClapTrap clap2(clap);

	clap.printStatus();

	clap.attack("B");
	clap.takeDamage(10);
	clap.printStatus();

	clap.takeDamage(45);
	clap.printStatus();

	clap.beRepaired(10);
	clap.printStatus();

	clap.beRepaired(45);
	clap.printStatus();

	clap2.printStatus();
	
	return 0;
}