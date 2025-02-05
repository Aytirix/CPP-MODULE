#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <cmath>
# include <iostream>
# include <sstream>
# include <stack>
# include <string>
#include <fstream>
#include <map>

// Date
#define YEAR_MIN 1900
#define YEAR_MAX 2100
#define MONTH_MIN 1
#define MONTH_MAX 12
#define DAY_MIN 1
#define DAY_MAX 31

class RPN
{
  public:
	// Constructors form canonical form
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	// Member functions
	int calculate(const std::string &expression);
  private:
	std::stack<int> _data;

	// Member functions
	bool ResolveOperator(const std::string &token);
	bool is_number(const std::string &token);
};

#endif