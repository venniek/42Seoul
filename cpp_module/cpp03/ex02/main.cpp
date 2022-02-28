#include "FragTrap.hpp"

int main() {
	ClapTrap clap("clap");
	FragTrap frag("frag");

	clap.printStatus();
	frag.printStatus();
	std::cout << std::endl;

	clap.attack(frag.getName());
	clap.printStatus();
	frag.takeDamage(clap.getAd());
	frag.printStatus();
	std::cout << std::endl;
	
	frag.attack(clap.getName());
	frag.printStatus();
	clap.takeDamage(frag.getAd());
	clap.printStatus();
	std::cout << std::endl;
	
	clap.beRepaired(10);
	clap.printStatus();
	std::cout << std::endl;
	
	frag.beRepaired(45);
	frag.printStatus();
	
	return 0;
}