#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Colors.hpp"

class Intern;

class Intern
{
public:
	// Constructors
	Intern();
	Intern(std::string target);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	// Destructors
	virtual ~Intern();

	// Getters and setters
	std::string getTarget() const { return _target; }


	// Exceptions

	// Functions
private:
	const std::string _target;
};

// Operators

std::ostream &operator<<(std::ostream &os, const Intern &Intern);

#endif