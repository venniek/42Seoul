#include "Conversion.hpp"

char* Conversion::getOrigin() const {
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

void Conversion::setType() {
	_type = checkTypeException();
	if (_type != Conversion::noType)
		return;
	if ((_origin[0] >= '0' && _origin[0] <= '9') || _origin[0] == '-' || _origin[0] == '.') {
		_type = checkTypeNumeric();
		if (_type != Conversion::noType)
			return;
	}
	if (_origin[1])
		return;
	_type = Conversion::charType;
}

int Conversion::checkTypeException() {
	char* doubleSpecial[] = { "inf", "+inf", "-inf", "nan" };
	char* floatSpecial[] = { "inff", "+inff", "-inff", "nanf" };

	for (int i = 0; i < 4; i++) {
		if (doubleSpecial[i] == _origin)
			return Conversion::doubleType;
		else if (floatSpecial[i] == _origin)
			return Conversion::floatType;
	}
}

int Conversion::checkTypeNumeric() {
	int i = 0;
	int dot = 0;

	if (_origin[0] == '-' && _origin[1])
		i++;
	if (_origin[i] == '.' && (_origin[i + 1] == 'f' || _origin[i + 1] == 0))
		return Conversion::noType;
	while (ft_isdigit(_origin[i]) || _origin[i] == '.') {
		if (_origin[i] == '.')
			dot++;
		if (dot > 1)
			return Conversion::noType;
		i++;
	}
	if (!_origin[i]) {
		if (dot == 1)
			return Conversion::doubleType;
		return Conversion::intType;
	}
	else if (_origin[i] == 'f' && !_origin[i + 1] && dot == 1)
		return Conversion::floatType;
	return Conversion::noType;
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
	if (_type == Conversion::noType) {
		std::cout << "No type" << std::endl;
		return;
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}

Conversion::Conversion(): _origin("") {
	std::cout << "Conversion default constructor called" << std::endl;
	_type = Conversion::noType;
	_inChar = 0;
	_inInt = 0;
	_inFloat = 0;
	_inDouble = 0;
}

Conversion::Conversion(char* origin): _origin(origin) {
	std::cout << "Conversion constructor with argument called" << std::endl;
	_type = Conversion::noType;
	_inChar = 0;
	_inInt = 0;
	_inFloat = 0;
	_inDouble = 0;
}

Conversion::Conversion(const Conversion& copy) {
	std::cout << "Conversion copy constructor called" << std::endl;
	*this = copy;
}

Conversion& Conversion::operator=(const Conversion& origin) {
	std::cout << "Conversion assignation operator called" << std::endl;
	if (this != &origin) {
		this->_origin = origin.getOrigin();
		this->_type = origin.getType();
		this->_inChar = origin.getChar();
		this->_inInt = origin.getInt();
		this->_inFloat = origin.getFloat();
		this->_inDouble = origin.getDouble();
	}
	return (*this);
}

Conversion::~Conversion() {
	std::cout << "Conversion destructor called" << std::endl;
}
