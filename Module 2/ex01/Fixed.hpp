#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

	int toInt() const;
	int getRawBits(void) const;
	Fixed& operator=(const Fixed& other);
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	int getValue() const;
private:
	int value;
	static const int fractionalBits = 8;
};

#endif