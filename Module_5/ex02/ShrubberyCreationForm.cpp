#include "ShrubberyCreationForm.hpp"


// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Aform("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << RED BOLD "ShrubberyCreationForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Aform("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << RED BOLD "ShrubberyCreationForm " RESET BLUE << getTarget() << GRAY " is created!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Aform("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	std::cout << RED BOLD "ShrubberyCreationForm " RESET BLUE << getTarget() << GRAY " copied!" << RESET << std::endl;
}

// Destructors

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED BOLD "ShrubberyCreationForm " RESET BLUE << getTarget() << GRAY " is destroyed!" << RESET << std::endl;
}

// Overloads

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << RED BOLD "ShrubberyCreationForm " RESET BLUE << getTarget() << GRAY " assigned!" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm)
{
	os << RED BOLD "ShrubberyCreationForm " RESET BLUE << ShrubberyCreationForm.getTarget() << GRAY " is created!" << RESET << std::endl;
	os << GRAY " Form is " RESET;
	if (ShrubberyCreationForm.getSigned())
		os << GREEN "signed" RESET;
	else
		os << RED
		   << "not signed" RESET;
	os << GRAY " with grade to sign " RESET << ShrubberyCreationForm.getGradeSigned() << GRAY " and grade to execute " RESET << ShrubberyCreationForm.getGradeExec();
	os << GRAY " and target name " RESET << ShrubberyCreationForm.getTarget();
	return os;
}

// Functions

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeExec())
		throw Aform::GradeTooLowException();
	std::ofstream file(getTarget().append("_shrubbery").c_str());
	if (!file.is_open())
		throw FileNotOpenException();
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
	file.close();
}
