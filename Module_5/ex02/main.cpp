#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Aform.hpp"
#include "Colors.hpp"

int main(void)
{
	system("clear");

	std::cout << BOLD YELLOW "Test ShrubberyCreationForm is signed" RESET << std::endl;
	Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 100);
	Aform *tree = new ShrubberyCreationForm("tree");
	try
	{
		std::cout << *bureaucrat << std::endl;
		std::cout << *tree << std::endl;
		bureaucrat->signForm(*tree);
		tree->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete tree;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm execute is not signed" RESET << std::endl;
	Bureaucrat *bureaucrat2 = new Bureaucrat("bureaucrat2", 100);
	Aform *tree2 = new ShrubberyCreationForm("tree2");
	try
	{
		std::cout << *bureaucrat2 << std::endl;
		std::cout << *tree2 << std::endl;
		tree2->execute(*bureaucrat2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat2;
	delete tree2;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm no permission to sign" RESET << std::endl;
	Bureaucrat *bureaucrat3 = new Bureaucrat("bureaucrat3", 150);
	Aform *tree3 = new ShrubberyCreationForm("tree3");
	try
	{
		std::cout << *bureaucrat3 << std::endl;
		std::cout << *tree3 << std::endl;
		bureaucrat3->signForm(*tree3);
		tree3->execute(*bureaucrat3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat3;
	delete tree3;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm no permission to execute" RESET << std::endl;
	Bureaucrat *bureaucrat4 = new Bureaucrat("bureaucrat4", 145);
	Aform *tree4 = new ShrubberyCreationForm("tree4");
	try
	{
		std::cout << *bureaucrat4 << std::endl;
		std::cout << *tree4 << std::endl;
		bureaucrat4->signForm(*tree4);
		tree4->execute(*bureaucrat4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat4;
	delete tree4;
	return (0);
}
