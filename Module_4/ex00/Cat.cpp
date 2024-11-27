#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat " << getType() << " is created!" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat " << getType() << " is created!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << "Cat " << getType() << " copied!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << getType() << " is destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
    }
    std::cout << "Cat assignation operator called!" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}