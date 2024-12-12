#include "A_Animal.hpp"

A_Animal::A_Animal() : _type("None")
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

A_Animal::A_Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

A_Animal::A_Animal(const A_Animal &other) : _type(other._type)
{
	std::cout << "Animal " << _type << " copied!" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal &other)
{
    if (this != &other) {
        _type = other._type;
	}
    std::cout << "Animal assignation operator called!" << std::endl;
    return *this;
}

A_Animal::~A_Animal()
{
	std::cout << "Animal " << _type << " is destroyed!" << std::endl;
}
