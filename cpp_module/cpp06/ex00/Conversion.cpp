#include "Conversion.hpp"

int Conversion::getOrigin() const {
	return _origin;
}

int Conversion::getType() const {
	return _type;
}

char Conversion::getChar() const {
	return _inChar;
}

int Conversion::getInt() const {
	return _inInt;
}

float Conversion::getFloat() const {
	return _inFloat;
}

double Conversion::getDouble() const {
	return _inDouble;
}


void Conversion::setAll() {
	stringstream origin(_origin);

	origin >> _inChar;
}

void Conversion::printChar() const {

}

void Conversion::printInt() const {

}

void Conversion::printFloat() const {

}

void Conversion::printDouble() const {

}

void Conversion::printAllType() const {
	printChar();
	printInt();
	printFloat();
	printDouble();
}


Conversion::Conversion(): _origin("") {
	std::cout << "Conversion default constructor called" << std::endl;
	setAll();
}

Conversion::Conversion(std::string& origin): _origin(origin) {
	std::cout << "Conversion constructor with argument called" << std::endl;
	setAll();
}

Conversion::Conversion(const Conversion& copy) {
	std::cout << "Conversion copy constructor called" << std::endl;
	*this = copy;
}

Conversion& Conversion::operator=(const Conversion& origin) {
	std::cout << "Conversion assignation operator called" << std::endl;
	if (this != &origin) {
		this->origin = origin.getOrigin();
		this->_type = origin.getType();
		this->_inChar = origin.getChar();
		this->_inInt = origin.getInt();
		this->_inFloat = origin.getFloat();
		this->_inDouble = origin.getDouble();
	}
	return (*this);
}

~Conversion() {
	std::cout << "Conversion destructor called" << std::endl;
}
