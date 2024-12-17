#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << RED BOLD "Intern " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

Intern::Intern(std::string target)
{
	std::cout << RED BOLD "Intern " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << RED BOLD "Intern " RESET BLUE << getTarget() << GRAY " copied!" << RESET << std::endl;
}

// Destructors

Intern::~Intern()
{
	std::cout << RED BOLD "Intern " RESET BLUE << getTarget() << GRAY " is destroyed!" << RESET << std::endl;
}

// Overloads

Intern &Intern::operator=(const Intern &other)
{
	std::cout << RED BOLD "Intern " RESET BLUE << getTarget() << GRAY " assigned!" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

// Functions
