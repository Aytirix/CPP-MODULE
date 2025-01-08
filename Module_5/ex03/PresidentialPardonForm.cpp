#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Aform("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << RED BOLD "PresidentialPardonForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Aform(target, 25, 5), _target(target)
{
	std::cout << RED BOLD "PresidentialPardonForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Aform(other._target, 25, 5), _target(other._target)
{
	std::cout << RED BOLD "PresidentialPardonForm " RESET BLUE << getTarget() << GRAY " copied!" << RESET << std::endl;
}

// Destructors

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED BOLD "PresidentialPardonForm " RESET BLUE << getTarget() << GRAY " is destroyed!" << RESET << std::endl;
}

// Overloads

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << RED BOLD "PresidentialPardonForm " RESET BLUE << getTarget() << GRAY " assigned!" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm)
{
	os << RED BOLD "PresidentialPardonForm " RESET BLUE << PresidentialPardonForm.getTarget() << GRAY " is created!" << RESET << std::endl;
	os << GRAY " Form is " RESET;
	if (PresidentialPardonForm.getSigned())
		os << GREEN "signed" RESET;
	else
		os << RED
		   << "not signed" RESET;
	os << GRAY " with grade to sign " RESET << PresidentialPardonForm.getGradeSigned() << GRAY " and grade to execute " RESET << PresidentialPardonForm.getGradeExec();
	os << GRAY " and target name " RESET << PresidentialPardonForm.getTarget();
	return os;
}

// Functions

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Aform::execute(executor);
	std::cout << "Informs that " << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

