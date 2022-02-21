#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &origin);
	int getRawBits() const;
	void setRawBits(int const raw);
	~Fixed();
};

#endif