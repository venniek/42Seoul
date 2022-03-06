#include "Cat.hpp"

void Cat::setType(const std::string type) {
	_type = "Cat_" + type;
}

void Cat::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}

Cat::Cat(): Animal() {
	_type = "Cat";
	brain = new Brain;
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string type): Animal() {
	_type = "Cat_" + type;
	brain = new Brain;
	std::cout << "Cat constructor with type \"" << type << "\" called" << std::endl;
}

Cat::Cat(const Cat &origin) {
	*this = origin;
}

Cat& Cat::operator=(const Cat &origin) {
	Animal::operator=(origin);
	*this->brain = *origin.getBrain();
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat " << _type << " destructor called" << std::endl;
}
