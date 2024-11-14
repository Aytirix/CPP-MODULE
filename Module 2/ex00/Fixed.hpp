#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	Fixed& operator=(const Fixed& other);

private:
	int value;
	static const int fractionalBits = 8;
};

#endif