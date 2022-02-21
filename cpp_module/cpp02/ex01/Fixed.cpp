#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) {
	fixedPointValue = num;
}

Fixed::Fixed(float num) {

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

float Fixed::toFloat() const {
	
}

int Fixed::toInt() const {
	return roundf()
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
} 