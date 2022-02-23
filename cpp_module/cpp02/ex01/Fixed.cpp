#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int i) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = i << fractionalBits;
}

Fixed::Fixed(float f) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(f * (1 << fractionalBits));
}


Fixed::Fixed(const Fixed &origin) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = origin.getRawBits();
}

int Fixed::getRawBits() const {
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = ref.getRawBits();
	return *this;
}

float Fixed::toFloat() const {
	return roundf(fixedPointValue * (1 << fractionalBits));
}

int Fixed::toInt() const {
	return fixedPointValue >> fractionalBits;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed &ref) {
	out << ref.getRawBits() / 256;
	return out;
}
