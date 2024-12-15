#ifndef Aform_HPP
#define Aform_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include "Colors.hpp"


class Bureaucrat;

class Aform
{
public:
	// Constructors and destructors
	Aform();
	Aform(std::string name, int grade_signed, int grade_exec);
	Aform(const Aform &other);
	Aform &operator=(const Aform &other);
	virtual ~Aform();

	// Getters and setters
	std::string getName() const { return _name; }
	bool getSigned() const { return _signed; }
	int getGradeSigned() const { return _grade_signed; }
	int getGradeExec() const { return _grade_exec; }
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class FormAlreadySignedException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form is already signed !";
		}
	};

	class GradeTooLowToSignException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade is too low to sign the form!";
		}
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Please sign the form before executing it.";
		}
	};

	class GradeTooLowToExecuteException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade is too low to execute the form!";
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

std::ostream &operator<<(std::ostream &os, const Aform &form);

#endif