#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Aform.hpp"
#include <iostream>
#include <cstdlib>
#include "Colors.hpp"

class Aform;

class Bureaucrat
{
public:
	// Constructors and destructors
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	virtual ~Bureaucrat();

	// Getters and setters
	std::string getName() const { return _name; }
	int getGrade() const { return _grade; }
	void increment();
	void decrement();

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
	int signForm(Aform &form);
private:
	const std::string _name;
	int _grade;
};

// Operators

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif