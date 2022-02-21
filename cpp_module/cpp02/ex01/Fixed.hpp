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
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed &origin);
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	~Fixed();
};

#endif