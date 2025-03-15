#include "RPN.hpp"
#include <fstream>

// Constructors form canonical form
RPN::RPN() : _data()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_data = other._data;
	return (*this);
}

RPN::~RPN()
{
	_data = std::stack<int>();
}

// Member functions

bool RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (!ResolveOperator(token))
				return (false);
		}
		else
		{
			if (is_number(token))
				_data.push(std::atoi(token.c_str()));
			else
			{
				std::cerr << "Error: invalid token" << std::endl;
				return (false);
			}
		}
	}
	if (_data.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (false);
	}
	else
		std::cout << _data.top() << std::endl;
	return (true);
}

bool RPN::ResolveOperator(const std::string &token)
{
	if (_data.size() < 2)
	{
		std::cerr << "Error: invalid operator" << std::endl;
		return (false);
	}
	int a = _data.top();
	_data.pop();
	int b = _data.top();
	_data.pop();
	if (token == "+")
		_data.push(a + b);
	else if (token == "-")
		_data.push(b - a);
	else if (token == "*")
		_data.push(a * b);
	else if (token == "/")
	{
		if (a == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				return (false);
			}
		_data.push(b / a);
	}
	return (true);
}

bool RPN::is_number(const std::string &token)
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(token[i]))
			return (false);
	}
	if (std::atoi(token.c_str()) > 9)
		return (false);
	return (true);
}
