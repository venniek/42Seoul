#include "Cure.hpp"

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure(): AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &type): AMateria(type) {
	std::cout << "Cure constructor with type \"" << type << "\" called" << std::endl;
}

Cure::Cure(const Cure& copy) {
	*this = copy;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& origin) {
	_type = origin.getType();
	std::cout << "Cure assignation operator called" << std::endl;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure " << _type << " destructor called" << std::endl;
}