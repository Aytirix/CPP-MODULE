#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other && this->value != other.value)
	{
		this->value = other.value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator++()
{
	++this->value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	--this->value;
	return *this;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.value = (this->value * other.value) >> Fixed::fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.value = (this->value << Fixed::fractionalBits) / other.value;
	return result;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.value = this->value + other.value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.value = this->value - other.value;
	return result;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->value != other.value;
}
