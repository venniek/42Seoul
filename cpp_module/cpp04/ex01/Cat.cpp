#include "Cat.hpp"

void Cat::setType(const std::string type) {
	_type = "Cat_" + type;
}

void Cat::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

Brain *Cat::getBrain() {
	return brain;
}

void Cat::setBrain(Brain *brain) {
	this->brain = brain;
}

Cat::Cat(): Animal() {
	brain = new Brain();
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string type): Animal() {
	brain = new Brain();
	_type = "Cat_" + type;
	std::cout << "Cat constructor with type \"" << type << "\" called" << std::endl;
}

Cat::Cat(const Cat &origin) {
	// this의 brain delete 먼저 해주기??
	*this = origin;
}

Cat& Cat::operator=(const Cat &origin) {
	Animal::operator=(origin);
	this->brain = origin.brain;
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
