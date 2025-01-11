#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include "Colors.hpp"
#include <sstream>

class ScalarConverter
{
public:
	// Getters and setters

	// Exceptions

	// Functions
	static void Convert(const std::string &literal);
private:
	// Constructors and destructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void PrintToAscii(const std::string &literal);
	static void PrintToInt(const std::string &literal);
	static void PrintToFloat(const std::string &literal);
	static void PrintToDouble(const std::string &literal);
};

// Operators

#endif