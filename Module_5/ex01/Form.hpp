#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include "Colors.hpp"


class Bureaucrat;

class Form
{
public:
	// Constructors and destructors
	Form();
	Form(std::string name, int grade_signed, int grade_exec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form();

	// Getters and setters
	std::string getName() const { return _name; }
	bool getSigned() const { return _signed; }
	int getGradeSigned() const { return _grade_signed; }
	int getGradeExec() const { return _grade_exec; }
	int beSigned(Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};

	// Functions
private:
	const std::string _name;
	bool _signed;
	const int _grade_signed;
	const int _grade_exec;
};

// Operators

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif