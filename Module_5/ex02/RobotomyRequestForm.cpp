#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : Aform("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Aform(target, 72, 45), _target(target)
{
	std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Aform(other._target, 72, 45), _target(other._target)
{
	std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " copied!" << RESET << std::endl;
}

// Destructors

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " is destroyed!" << RESET << std::endl;
}

// Overloads

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " assigned!" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm)
{
	os << RED BOLD "RobotomyRequestForm " RESET BLUE << RobotomyRequestForm.getTarget() << GRAY " is created!" << RESET << std::endl;
	os << GRAY " Form is " RESET;
	if (RobotomyRequestForm.getSigned())
		os << GREEN "signed" RESET;
	else
		os << RED
		   << "not signed" RESET;
	os << GRAY " with grade to sign " RESET << RobotomyRequestForm.getGradeSigned() << GRAY " and grade to execute " RESET << RobotomyRequestForm.getGradeExec();
	os << GRAY " and target name " RESET << RobotomyRequestForm.getTarget();
	return os;
}

// Functions

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Aform::execute(executor);

	std::srand(std::time(0));
	int random = std::rand() % 2;
	if (random == 0)
		std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " has been robotomized!" << RESET << std::endl;
	else
		std::cout << RED BOLD "RobotomyRequestForm " RESET BLUE << getTarget() << GRAY " failed to robotomize!" << RESET << std::endl;
}
