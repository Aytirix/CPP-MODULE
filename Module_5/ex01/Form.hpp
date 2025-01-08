#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

#define RESET_TERM "\033[0m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[90m"

#define BOLD "\033[1m"		// Gras
#define UNDERLINE "\033[4m" // Souligné
#define BLINK "\033[5m"		// Clignotant
#define REVERSE "\033[7m"	// Surligné
#define CONCEALED "\033[8m" // Invisible

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
	void beSigned(Bureaucrat &bureaucrat);

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