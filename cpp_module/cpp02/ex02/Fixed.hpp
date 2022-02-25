#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	Fixed();
	explicit Fixed(const int i);
	explicit Fixed(const float f);
	Fixed(const Fixed &origin);

	Fixed& operator=(const Fixed &ref);
	a = b
	a.operator=(b)

	bool operator>(const Fixed &ref);
	bool operator<(const Fixed &ref);
	bool operator>=(const Fixed &ref);
	bool operator<=(const Fixed &ref);
	bool operator==(const Fixed &ref);
	bool operator!=(const Fixed &ref);
	
	Fixed& operator+(const Fixed &ref);
	Fixed& operator-(const Fixed &ref);
	Fixed& operator*(const Fixed &ref);
	Fixed& operator/(const Fixed &ref);

	void operator++(const Fixed &ref);
	void operator--(const Fixed &ref);


	int& min(const Fixed &ref1, const Fixed &ref2);
	int& min(const Fixed &ref1, const Fixed &ref2);


	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
	~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref);

#endif