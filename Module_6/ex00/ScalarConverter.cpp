#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << RED BOLD "ScalarConverter " GRAY " is created!" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << RED BOLD "ScalarConverter " GRAY " copied!" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << RED BOLD "ScalarConverter " GRAY " assigned!" << RESET << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED BOLD "ScalarConverter " GRAY " is destroyed!" << RESET << std::endl;
}
