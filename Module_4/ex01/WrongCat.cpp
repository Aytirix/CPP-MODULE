#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat " << getType() << " is created!" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat " << getType() << " is created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat " << getType() << " copied!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << getType() << " is destroyed!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this != &other) {
        WrongAnimal::operator=(other);
        _type = other._type;
    }
    std::cout << "WrongCat assignation operator called!" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow Wrongmeow" << std::endl;
}