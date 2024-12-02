#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cerr << "Memory allocation failed for _brain" << std::endl;
		exit(1);
	}
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
	delete _brain;
	std::cout << "Cat " << getType() << " is destroyed!" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
		_brain = new Brain(*other._brain);
		if (_brain == NULL)
		{
			std::cerr << "Memory allocation failed for _brain" << std::endl;
			exit(1);
		}
		*_brain = *other._brain;
    }
    std::cout << "Cat assignation operator called!" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

void Cat::getIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (_brain->getIdea(i).empty())
			continue;
		std::cout << "Idea " << i << ": " << _brain->getIdea(i) << std::endl;
	}
}
void Cat::setIdeas(int i, std::string ideas)
{
	_brain->setIdea(i, ideas);
}
