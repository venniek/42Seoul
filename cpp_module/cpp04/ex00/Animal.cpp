#include "Animal.hpp"

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string type) {
	_type = "Animal_" + type;
}

void Animal::makeSound() const {
	std::cout << _type << " is making sound... animalanimalanimal..." << std::endl;
}

Animal::Animal(): _type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): _type("Animal_" + type) {
	std::cout << "Animal constructor with type \"" << type << "\" called" << std::endl;
}

Animal::Animal(const Animal &origin) {
	*this = origin;
}

Animal& Animal::operator=(const Animal &origin) {
	this->_type = origin._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}
