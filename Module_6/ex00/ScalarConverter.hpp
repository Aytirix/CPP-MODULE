#ifndef SCARLARCONVERTER_HPP
# define SCARLARCONVERTER_HPP

# include "Colors.hpp"
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>

class ScalarConverter
{
  public:
	// Getters and setters

	// Exceptions

	// Functions
	static void convert(const std::string &literal);

  private:
	// Constructors and destructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static bool isCharLiteral(const std::string &literal);
	static bool isIntLiteral(const std::string &literal);
	static bool isFloatLiteral(const std::string &literal, int check_max);
	static bool isDoubleLiteral(const std::string &literal);

	static void handleChar(char c);
	static void handleInt(int value);
	static void handleFloat(float value);
	static void handleDouble(double value);

	static void PrintChar(int value);
	static void PrintInt(long value);
};

// Operators

#endif