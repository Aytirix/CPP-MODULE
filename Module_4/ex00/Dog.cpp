#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog " << getType() << " is created!" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog " << getType() << " is created!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << "Dog " << getType() << " copied!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog " << getType() << " is destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
    }
    std::cout << "Dog assignation operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}