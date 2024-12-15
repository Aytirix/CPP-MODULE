#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Aform.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Colors.hpp"

class Aform;

class RobotomyRequestForm : public Aform
{
public:
	// Constructors
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	// Destructors
	virtual ~RobotomyRequestForm();

	// Getters and setters
	std::string getTarget() const { return _target; }


	// Exceptions

	// Functions
	void execute(Bureaucrat const &executor) const;
private:
	const std::string _target;
};

// Operators

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm);

#endif