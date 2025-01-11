#include "ScalarConverter.hpp"

// Constructors and destructors

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
void ScalarConverter::PrintToAscii(const std::string &literal)
{
	std::istringstream iss(literal);
	int asciiValue;
	bool IsDigit = true;
	for (int i = 0; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
        {
            IsDigit = false;
			break ;
        }
    }
	if (!(iss >> asciiValue) || !std::isprint(static_cast<char>(asciiValue)) || !IsDigit)
	{
		std::cerr << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: '" << static_cast<char>(asciiValue) << "'" << std::endl;
}

void ScalarConverter::PrintToInt(const std::string &literal)
{
	std::istringstream iss(literal);
	int intValue;
	if (!(iss >> intValue))
	{
		std::cerr << "int: Invalid input" << std::endl;
		return;
	}
	std::cout << "int: " << intValue << std::endl;
}

void ScalarConverter::PrintToFloat(const std::string &literal)
{
}

void ScalarConverter::PrintToDouble(const std::string &literal)
{
}

// Functions
void ScalarConverter::Convert(const std::string &literal)
{
	ScalarConverter::PrintToAscii(literal);
	ScalarConverter::PrintToInt(literal);
	ScalarConverter::PrintToFloat(literal);
	ScalarConverter::PrintToDouble(literal);
}
