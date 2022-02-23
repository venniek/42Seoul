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
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat(float f) const;
	int toInt(int i) const;
	~Fixed();
};

// void operator<<(const Fixed &ref);

#endif