#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <map>

int main(void)
{
	system("clear");

	std::cout << BOLD YELLOW "Test to already signed form" RESET << std::endl;
	Bureaucrat bureaucrat("John", 50);
	Form form("TOP SECRET", 50, 50);
	try
	{
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << BOLD YELLOW "Test to no permission to sign form" RESET << std::endl;
	Bureaucrat bureaucrat2("John 2", 51);
	Form form2("TOP SECRET 2", 50, 50);
	try
	{
		std::cout << bureaucrat2 << std::endl;
		std::cout << form2 << std::endl;
		bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
