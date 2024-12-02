#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getValue() const {
	return this->value;
}

int Fixed::toInt() const
{
	return this->value >> Fixed::fractionalBits;
}

float Fixed::toFloat() const
{
	return (float)this->value / (1 << Fixed::fractionalBits);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a.toFloat() : b.toFloat();
}


Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a.toFloat() : b.toFloat();
}

