#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>


Base	*generate(void)
{
	int	rand_choice;

	rand_choice = rand() % 3;
	if (rand_choice == 0) {
		std::cout << BOLD YELLOW "Generated: A" RESET << std::endl;
		return (new A());
	} else if (rand_choice == 1) {
		std::cout << BOLD YELLOW "Generated: B" RESET << std::endl;
		return (new B());
	} else {
		std::cout << BOLD YELLOW "Generated: C" RESET << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << BOLD MAGENTA "Identify from pointer : A" RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BOLD MAGENTA "Identify from pointer : B" RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BOLD MAGENTA "Identify from pointer : C" RESET << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << BOLD GREEN "Identify from reference : A" << std::endl;
		(void)a;
	}
	catch (std::exception &)
	{
		std::cout << BOLD RED "Identify from reference : Not A" RESET << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << BOLD GREEN "Identify from reference : B" << std::endl;
		(void)b;
	}
	catch (std::exception &)
	{
		std::cout << BOLD RED "Identify from reference : Not B" RESET << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << BOLD GREEN "Identify from reference : C" << std::endl;
		(void)c;
	}
	catch (std::exception &)
	{
		std::cout << BOLD RED "Identify from reference : Not C" RESET << std::endl;
	}
}

int	main(void)
{
	system("clear");
	Base	*instance;

	srand(static_cast<unsigned int>(time(0)));
	instance = generate();
	identify(instance);
	identify(*instance);
	delete	instance;
	return (0);
}
