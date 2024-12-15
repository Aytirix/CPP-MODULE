#include "Aform.hpp"

Aform::Aform() : _name("FormDefault"), _signed(0), _grade_signed(150), _grade_exec(150)
{
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " is created!" << RESET << std::endl;
}

Aform::Aform(std::string name, int grade_signed, int grade_exec) : _name(name), _signed(0), _grade_signed(grade_signed), _grade_exec(grade_exec)
{
	if (grade_signed < 1 || grade_exec < 1)
		throw Aform::GradeTooHighException();
	else if (grade_signed > 150 || grade_exec > 150)
		throw Aform::GradeTooLowException();
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " is created!" << RESET << std::endl;
}

Aform::Aform(const Aform &other) : _name(other._name), _signed(other._signed), _grade_signed(other._grade_signed), _grade_exec(other._grade_exec)
{
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " copied!" << RESET << std::endl;
}

Aform &Aform::operator=(const Aform &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " assigned!" << RESET << std::endl;
	return *this;
}

Aform::~Aform()
{
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " is destroyed!" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Aform &form)
{
	os << WHITE BOLD "Form " RESET BLUE << form.getName() << GRAY " is " RESET;
	if (form.getSigned())
		os << GREEN "signed" RESET;
	else
		os << RED "not signed" RESET;
	os << GRAY " with grade to sign " RESET << form.getGradeSigned() << GRAY " and grade to execute " RESET << form.getGradeExec();
	return os;
}

void Aform::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_signed)
	{
		if (_signed == 1)
			throw Aform::FormAlreadySignedException();
		_signed = true;
		std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " is signed by " RESET << bureaucrat.getName() << std::endl;
	}
	else
		throw Aform::GradeTooLowToSignException();
}

void Aform::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeExec())
		throw Aform::GradeTooLowToExecuteException();
	if (!_signed)
		throw Aform::FormNotSignedException();
	std::cout << WHITE BOLD "Form " RESET BLUE << getName() << GRAY " is executed by " RESET << executor.getName() << std::endl;
}
