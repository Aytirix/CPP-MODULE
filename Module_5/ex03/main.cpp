#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Aform.hpp"
#include "Colors.hpp"

int main(void)
{
	system("clear");

	std::cout << BOLD YELLOW "Test presidential pardon is signed" RESET << std::endl;
	Bureaucrat *bureaucrat = new Bureaucrat("bubu", 1);
	Intern *intern = new Intern();
	Aform *form = intern->makeForm("presidential pardon", "Top secret");
	try
	{
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		form->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	delete intern;

	std::cout << BOLD YELLOW "\nTest robotomy request is signed" RESET << std::endl;
	intern = new Intern();
	form = intern->makeForm("robotomy request", "Top secret");
	try
	{
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		form->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	delete intern;

	std::cout << BOLD YELLOW "\nTest shrubbery creation is signed" RESET << std::endl;
	intern = new Intern();
	form = intern->makeForm("shrubbery creation", "Top secret");
	try
	{
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		form->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	delete intern;

	std::cout << BOLD YELLOW "\nTest Form not exist" RESET << std::endl;
	intern = new Intern();
	try
	{
		form = intern->makeForm("form not exist", "Top secret");
		form->beSigned(*bureaucrat);
		form->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete intern;


	std::cout << std::endl << std::endl << BOLD YELLOW "Appuyer sur une touche pour finir le test" RESET << std::endl;
	std::cin.get();
	system("clear");

	system("rm -f 'Top secret_shrubbery'");
	return (0);
}
