#ifndef __CONVERSION_H__
#define __CONVERSION_H__

#include <iostream>
#include <string>
#include <sstream>

class Conversion {
private:
	std::string _origin;
	int _type;
	char _inChar;
	int _inInt;
	float _inFloat;
	double _inDouble;

	static const int noType = -1;
	static const int charType = 0;
	static const int intType = 1;
	static const int floatType = 2;
	static const int doubleType = 3;

public:
	int getOrigin() const;
	int getType() const;
	char getChar() const;
	int getInt() const;
	float getFloat() const;
	double getDouble() const;

	void setAll();
	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;
	void printAllType() const;

	Conversion();
	Conversion(std::string& origin);
	Conversion(const Conversion& copy);
	Conversion& operator=(const Conversion& origin);
	~Conversion();
};

#endif