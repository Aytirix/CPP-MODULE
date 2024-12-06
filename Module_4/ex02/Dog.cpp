#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog " << getType() << " is created!" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog " << getType() << " is created!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog " << getType() << " copied!" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog " << getType() << " is destroyed!" << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignation operator called!" << std::endl;
    if (this != &src)
	{
        this->_type = src._type;
		this->_brain = new Brain(*src._brain);
		if (this->_brain == NULL)
		{
			std::cerr << "Memory allocation failed for _brain" << std::endl;
			exit(1);
		}
    }
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (_brain->getIdea(i).empty())
			continue;
		std::cout << "Idea " << i << ": " << _brain->getIdea(i) << std::endl;
	}
}
void Dog::setIdeas(int i, std::string ideas)
{
	_brain->setIdea(i, ideas);
}

Brain *Dog::getBrain(void)
{
	return _brain;
}
