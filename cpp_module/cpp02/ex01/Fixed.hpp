#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(int i);
	Fixed(float f);
	Fixed(const Fixed &origin);
	int getRawBits() const;
	void setRawBits(int const raw);
	void operator=(const Fixed &ref);
	~Fixed();
};

#endif