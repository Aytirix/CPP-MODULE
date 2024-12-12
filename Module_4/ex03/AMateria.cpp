#include "A_Animal.hpp"

AMateria::AMateria() : _type("None")
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

AMateria::AMateria(std::string type) : _type(type)
{
	std::cout << "Animal " << _type << " is created!" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << "Animal " << _type << " copied!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
    if (this != &other) {
        _type = other._type;
	}
    std::cout << "Animal assignation operator called!" << std::endl;
    return *this;
}

AMateria::~AMateria()
{
	std::cout << "Animal " << _type << " is destroyed!" << std::endl;
}
