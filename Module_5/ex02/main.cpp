#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Aform.hpp"
#include "Colors.hpp"
#include <map>

int main(void)
{
	system("clear");

	std::cout << BOLD YELLOW "Test ShrubberyCreationForm" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("John", 1);
		ShrubberyCreationForm ee("home");
		std::cout << bureaucrat << std::endl;
		std::cout << ee << std::endl;
		bureaucrat.signForm(ee);
		ee.execute(bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
