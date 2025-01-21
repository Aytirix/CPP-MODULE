#include "ScalarConverter.hpp"

// Constructors and destructors

ScalarConverter::ScalarConverter()
{
	std::cout << RED BOLD "ScalarConverter " GRAY " is created!" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << RED BOLD "ScalarConverter " GRAY " copied!" << RESET << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << RED BOLD "ScalarConverter " GRAY " assigned!" << RESET << std::endl;
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED BOLD "ScalarConverter " GRAY " is destroyed!" << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty literal" << std::endl;
		return ;
	}
	if (isCharLiteral(literal))
		handleChar(literal[0]);
	else if (isIntLiteral(literal))
		handleInt(std::atoi(literal.c_str()));
	else if (isFloatLiteral(literal))
		handleFloat(static_cast<float>(std::atof(literal.c_str())));
	else if (isDoubleLiteral(literal))
		handleDouble(std::atof(literal.c_str()));
	else
		std::cerr << "Error: Unknown literal format" << std::endl;
}

bool ScalarConverter::isCharLiteral(const std::string &literal)
{
	return (literal.size() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]));
}

bool ScalarConverter::isIntLiteral(const std::string &literal)
{
	char	*end;
	long	value;

	value = std::strtol(literal.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	return (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloatLiteral(const std::string &literal)
{
	char	*end;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal.size() > 1 && literal[literal.size() - 1] == 'f')
	{
		std::string tmp = literal;
		tmp.erase(tmp.size() - 1);
		std::strtod(tmp.c_str(), &end);
		return (*end == '\0');
	}
	return (false);
}

bool ScalarConverter::isDoubleLiteral(const std::string &literal)
{
	char	*end;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::handleChar(char c)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::PrintChar(int value)
{
	if (value >= 0 && value <= 127 &&  std::isfinite(value) && std::isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	else
	{
		if (value < 0 || value > 127|| std::isnan(value) || std::isinf(value))
			std::cout << "char: impossible\n";
		else
			std::cout << "char: Non displayable\n";
	}
}

void ScalarConverter::PrintInt(long value)
{
	if (std::isfinite(value) && value <= std::numeric_limits<int>::max()
		&& value >= std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(value) << "\n";
	else
        std::cout << "int: impossible\n";
}

void ScalarConverter::handleInt(int value)
{
	std::cout << std::fixed << std::setprecision(1);
	PrintChar(value);
	PrintInt(value);
	std::cout << "float: " << static_cast<float>(value) << "f\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::handleFloat(float value)
{
	std::cout << std::scientific << std::setprecision(0);
	PrintChar(value);
	PrintInt(value);
	std::cout << "float: " << value << "f\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::handleDouble(double value)
{
	std::cout << std::scientific << std::setprecision(0);
	PrintChar(value);
	PrintInt(value);
	std::cout << "float: " << static_cast<float>(value) << "f\n";
	std::cout << "double: " << value << "\n";
}
