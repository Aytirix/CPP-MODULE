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

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other && this->value != other.value) {
		this->value = other.value;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
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
