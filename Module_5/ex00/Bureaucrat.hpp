#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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
private:
	const std::string _name;
	int _grade;
};

// Operators

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif