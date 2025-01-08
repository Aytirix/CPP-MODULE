#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Aform.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


class Aform;

class PresidentialPardonForm : public Aform
{
public:
	// Constructors
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	// Destructors
	virtual ~PresidentialPardonForm();

	// Getters and setters
	std::string getTarget() const { return _target; }


	// Exceptions

	// Functions
	void execute(Bureaucrat const &executor) const;
private:
	const std::string _target;
};

// Operators

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm);

#endif