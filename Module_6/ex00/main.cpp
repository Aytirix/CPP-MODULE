#include "ScalarConverter.hpp"
#include "Colors.hpp"

int main(int ac, char **av)
{
	system("clear");

	if (ac != 2) {
		std::cerr << BOLD RED "Error: Invalid number of arguments, please provide a literal" RESET << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);
	return (0);
}
