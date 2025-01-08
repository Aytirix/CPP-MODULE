#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << GREEN BOLD "Intern " RESET GRAY " is created!" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << GREEN BOLD "Intern " RESET GRAY " copied!" << RESET << std::endl;
	*this = other;
}

// Destructors

Intern::~Intern()
{
	std::cout << GREEN BOLD "Intern " RESET GRAY " is destroyed!" << RESET << std::endl;
}

// Overloads

Intern &Intern::operator=(const Intern &other)
{
	std::cout << GREEN BOLD "Intern " RESET GRAY " assigned!" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

// Functions

Aform *Intern::makeForm(std::string form, std::string target)
{

		Aform* ret = NULL;
        const char* formNames[] = {
            "presidential pardon",
            "robotomy request",
            "shrubbery creation"
        };

		int i  = 0;
		for (; i < 3; i++)
			if (form == formNames[i])
				break;

		switch (i)
		{
			case 0:
				ret = new PresidentialPardonForm(target);
				break;
			case 1:
				ret = new RobotomyRequestForm(target);
				break;
			case 2:
				ret = new ShrubberyCreationForm(target);
				break;
			default:
				throw Intern::FromNotExist();
		}
		std::cout << GREEN BOLD "Intern " RESET GRAY " creates " GREEN << formNames[i] << GRAY " form." RESET << std::endl;
		return ret;
}
