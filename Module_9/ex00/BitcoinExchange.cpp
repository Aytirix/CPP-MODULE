#include "BitcoinExchange.hpp"
#include <fstream>

// Constructors form canonical form
BitcoinExchange::BitcoinExchange() : _data()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	_data.clear();
}

// Member functions
bool BitcoinExchange::loadData(const char *filename)

{
	double rate;

	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (false);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("date,exchange_rate") != std::string::npos)
			continue ;
		std::istringstream iss(line);
		std::string currency;
		if (!std::getline(iss, currency, ',') || !(iss >> rate))
		{
			std::cerr << "Error: invalid line in file " << filename << std::endl;
			std::cerr << "Line: " << line << std::endl;
			return (false);
		}
		if (!checkValidDate(currency))
		{
			std::cerr << "Error: invalid date in file " << filename << std::endl;
			std::cerr << "Line number: " << _data.size() + 1 << std::endl;
			std::cerr << "Format should be YYYY-MM-DD" << std::endl;
			std::cerr << "Date: " << currency << std::endl;
			return (false);
		}
		if (rate < 0)
		{
			std::cerr << "Error: invalid exchange rate in file " << filename << std::endl;
			std::cerr << "Line number: " << _data.size() + 1 << std::endl;
			std::cerr << "Exchange rate should be positive" << std::endl;
			std::cerr << "Rate: " << rate << std::endl;
			return (false);
		}
		_data[currency] = rate;
	}
	return (true);
}

bool BitcoinExchange::CheckInputUser(const char *filename)
{
	double rate;

	if (_data.empty())
	{
		std::cerr << "Error: no data loaded" << std::endl;
		return (false);
	}
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (false);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("date | value") != std::string::npos)
			continue ;
		std::istringstream iss(line);
		std::string currency;
		if (!std::getline(iss, currency, '|') || !(iss >> rate))
			std::cerr << "Error: Bad input => " << line << std::endl;
		else if (!checkValidDate(currency))
			std::cerr << "Error: Bad input => " << currency << std::endl;
		else if (rate < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (rate > 2147483647)
			std::cerr << "Error: too large a number." << std::endl;
		else
		{
			double price = getRate(currency);
			if (price < 0)
				std::cerr << "Error: no exchange rate for date " << currency << std::endl;
			else
				std::cout << currency << "=> " << rate << " = " << rate * price << std::endl; 
		}
	}
	return (true);
}

double BitcoinExchange::getRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = _data.find(date);
    if (it != _data.end())
        return (it->second);
    it = _data.lower_bound(date);
    if (it != _data.begin())
    {
        --it;
        return (it->second);
    }
    return (-1);
}
