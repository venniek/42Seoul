#include "Zombie.hpp"

int main()
{
	Zombie zombie1;
	Zombie* zombie2 = zombie1.newZombie("nayHeap");
	
	zombie1.announce();
	zombie2->announce();
	zombie1.randomChump("nayStack");
	delete zombie2;
	return 0;
}