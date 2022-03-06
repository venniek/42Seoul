#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

void test_normal(void) {
	const Animal* i = new Cat("i");
	const Animal* j = new Dog("j");
	const Animal* k = new Dog("k");

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	*(const_cast<Animal*>(k)) = *(const_cast<Animal*>(j));
	k->makeSound();
	std::cout << std::endl;

	delete k;
	delete j;
	delete i;
}

void test_array(void) {
	Animal* meta[B_COUNT / 20];
	Dog* copyDog = new Dog("copy");

	for (int i = 0 ; i < B_COUNT / 20 ; ++i) {
		if (!(i % 2)) {
			meta[i] = new Cat(std::to_string(i / 2 + 1));
		} else {
			meta[i] = new Dog(std::to_string(i / 2 + 1));
		}
	}
	std::cout << std::endl << "copy test" << std::endl;
	*copyDog = *dynamic_cast<Dog*>(meta[1]);
	meta[1]->setType("change");
	std::cout << "meta[1]'s type: " << meta[1]->getType() << std::endl;
	std::cout << "copyDog's type: " << copyDog->getType() << std::endl;
	std::cout << std::endl;
	for (int i = 0 ; i < B_COUNT / 20 ; ++i)
		delete meta[i];
	delete copyDog;
}

int main(void) {
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
	test_normal();
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
	test_array();
	std::cout << std::setfill('=') << std::setw(50) << "=\n" << std::setfill(' ');
	return 0;
}