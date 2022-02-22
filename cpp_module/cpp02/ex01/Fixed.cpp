#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = origin.getRawBits();
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

void Fixed::operator=(const Fixed &ref) {
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = ref.getRawBits();
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
} 