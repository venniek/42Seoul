#include "WrongCat.hpp"

void WrongCat::setType(const std::string type) {
	_type = "WrongCat_" + type;
}

void WrongCat::makeSound() const {
	std::cout << _type << " is making sound... Meow Meow Meow..." << std::endl;
}

WrongCat::WrongCat(): WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal() {
	_type = "WrongCat_" + type;
	std::cout << "WrongCat constructor with type \"" << type << "\" called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin) {
	*this = origin;
}

WrongCat& WrongCat::operator=(const WrongCat &origin) {
	WrongAnimal::operator=(origin);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
