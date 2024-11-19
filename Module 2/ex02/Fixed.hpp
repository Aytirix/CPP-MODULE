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

	Fixed& operator=(const Fixed& other);
	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	int getValue() const;
	int toInt() const;
	float toFloat() const;
	static Fixed max(const Fixed &a, const Fixed &b);
	static Fixed min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
private:
	int value;
	static const int fractionalBits = 8;
};

#endif