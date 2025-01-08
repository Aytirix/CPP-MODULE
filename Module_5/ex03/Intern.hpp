#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	// Destructors
	virtual ~Intern();

	// Getters and setters
	std::string getTarget() const { return _target; }

	// Exceptions
	class FromNotExist : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Your form not exist!";
		}
	};

	// Functions
	Aform *makeForm(std::string form, std::string target);

private:
	const std::string _target;
};

#endif