#include "Bureaucrat.hpp"
#include <map>

int main(void)
{
	system("clear");

	std::cout << BOLD YELLOW "Default constructor" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat1;
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.increment();
		bureaucrat1.decrement();
		bureaucrat1.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLD YELLOW "Name constructor" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat2("John");
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.increment();
		bureaucrat2.decrement();
		bureaucrat2.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLD YELLOW "Name and grade constructor" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat2("Jonny", 1);
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decrement();
		bureaucrat2.increment();
		bureaucrat2.increment();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLD YELLOW "Name and grade constructor to TOOO HIGH" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat2("Jonny", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << BOLD YELLOW "Name and grade constructor to TOOO LOW" RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat2("Jonny", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
