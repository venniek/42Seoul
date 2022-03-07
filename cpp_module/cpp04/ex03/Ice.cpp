#include "Ice.hpp"

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice(): AMateria("ice") {
	std:cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &type): AMateria(type) {
	std::cout << "Ice constructor with type \"" << type << "\" called" << std::endl;
}

Ice::Ice(const Ice& copy) {
	*this = copy;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& origin) {
	_type = origin.getType();
	std::cout << "Ice assignation operator called" << std::endl;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice " << _type << " destructor called" << std::endl;
}