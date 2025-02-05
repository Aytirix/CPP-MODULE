#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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

class BitcoinExchange
{
  public:
	// Constructors form canonical form
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	// Member functions
	bool loadData(const char *filename);
	bool CheckInputUser(const char *filename);
  private:
	std::map<std::string, double> _data;

	// Member functions
	double getRate(const std::string &date);
};

bool checkValidDate(const std::string &date);

#endif