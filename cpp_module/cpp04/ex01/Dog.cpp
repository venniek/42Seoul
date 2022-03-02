#include "Dog.hpp"

void Dog::setType(const std::string type) {
	_type = "Dog_" + type;
}

void Dog::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

Brain *Dog::getBrain() {
	return brain;
}

void Dog::setBrain(Brain *brain) {
	this->brain = brain;
}

Dog::Dog(): Animal() {
	brain = new Brain();
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal() {
	brain = new Brain();
	_type = "Dog_" + type;
	std::cout << "Dog constructor with type \"" << type << "\" called" << std::endl;
}

Dog::Dog(const Dog &origin) {
	// this의 brain delete 먼저 해주기??
	*this = origin;
}

Dog& Dog::operator=(const Dog &origin) {
	Animal::operator=(origin);
	this->brain = origin.brain;
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}
