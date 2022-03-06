#include "Dog.hpp"

void Dog::setType(const std::string type) {
	_type = "Dog_" + type;
}

void Dog::makeSound() const {
	std::cout << _type << " is making sound... BowWow BowWow BowWow..." << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}

Dog::Dog(): Animal() {
	_type = "Dog";
	brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal() {
	_type = "Dog_" + type;
	brain = new Brain;
	std::cout << "Dog constructor with type \"" << type << "\" called" << std::endl;
}

Dog::Dog(const Dog &origin) {
	*this = origin;
}

Dog& Dog::operator=(const Dog &origin) {
	Animal::operator=(origin);
	*this->brain = *origin.getBrain();
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog " << _type << " destructor called" << std::endl;
}
