#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("None")
{
	std::cout << "WrongAnimal " << _type << " is created!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal " << _type << " is created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal " << _type << " copied!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other) {
        _type = other._type;
	}
    std::cout << "WrongAnimal assignation operator called!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " is destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong No sound!" << std::endl;
}
