#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string name)
{
	std::cout << "Brain name constructor called" << std::endl;
	(void)name;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	(void)src;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i].assign(src._ideas[i]);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (_ideas[i]);
	return ("The index must be between 0 and 99, and you have used the index "
		+ i);
}

const std::string *Brain::getIdeasAddress(int i) const
{
	if (i >= 0 && i < 100)
	{
		const std::string &ptr = _ideas[i];
		return (&ptr);
	}
	return (NULL);
}

void Brain::setIdea(int i, std::string ideas)
{
	if (i >= 0 && i < 100)
		_ideas[i] = ideas;
	else
		std::cerr << "The index must be between 0 and 99, and you have used the index " << i << std::endl;
}
