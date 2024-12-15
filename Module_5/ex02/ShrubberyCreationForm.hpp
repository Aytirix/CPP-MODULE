#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include "Aform.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Colors.hpp"

class Aform;

class ShrubberyCreationForm : public Aform
{
public:
	// Constructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	// Destructors
	virtual ~ShrubberyCreationForm();

	// Getters and setters
	std::string getTarget() const { return _target; }


	// Exceptions
	class FileNotOpenException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "File not open!";
		}
	};

	// Functions
	void execute(Bureaucrat const &executor) const;
private:
	const std::string _target;
};

// Operators

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm);

#endif