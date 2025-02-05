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

int RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (!ResolveOperator(token))
			{
				std::cerr << "Error: invalid operator" << std::endl;
				return (0);
			}
		}
		else
		{
			if (is_number(token))
				_data.push(std::atoi(token.c_str()));
			else
			{
				std::cerr << "Error: invalid token" << std::endl;
				return (0);
			}
		}
	}
	if (_data.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (0);
	}
	else
		std::cout << _data.top() << std::endl;
	return (_data.top());
}

bool RPN::ResolveOperator(const std::string &token)
{
	if (_data.size() < 2)
		return (false);
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
		_data.push(b / a);
	return (true);
}

bool RPN::is_number(const std::string &token)
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		std::cout << "token[i]: " << token[i] << std::endl;
		if (!std::isdigit(token[i]))
			return (false);
	}
	return (true);
}
