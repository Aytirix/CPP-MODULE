#include "Animal.hpp"

Animal::Animal() : _type("None")
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal " << _type << " copied!" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other) {
        _type = other._type;
	}
    std::cout << "Animal assignation operator called!" << std::endl;
    return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " is destroyed!" << std::endl;
}
