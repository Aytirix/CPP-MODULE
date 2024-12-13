#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unkonw"), _grade(150)
{
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " is created!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " is created!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " is created!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	_grade = other.getGrade();
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " copied!" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " assigned!" << RESET << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GRAY " is destroyed!" << RESET << std::endl;
}
void Bureaucrat::increment()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << GREEN BOLD " upgraded " RESET GRAY "to grade " BOLD CYAN UNDERLINE << getGrade() << RESET << std::endl;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << RED BOLD "Bureaucrat " RESET BLUE << getName() << RED BOLD " downgraded " RESET GRAY "to grade " BOLD CYAN UNDERLINE << getGrade() << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << RED BOLD "Bureaucrat " RESET BLUE << bureaucrat.getName() << GRAY " has grade " BOLD CYAN UNDERLINE << bureaucrat.getGrade() << RESET << std::endl;
	return os;
}