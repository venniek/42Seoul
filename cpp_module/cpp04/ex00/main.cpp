#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "===============================" << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongcat->makeSound();

	return 0;
}