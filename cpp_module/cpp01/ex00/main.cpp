#include "Zombie.hpp"

int main()
{
	Zombie zombie1;
	Zombie* zombie2 = Zombie::newZombie("nayHeap");
	
	zombie1.announce();
	zombie2->announce();
	Zombie::randomChump("nayStack");
	delete zombie2;
	return 0;
}