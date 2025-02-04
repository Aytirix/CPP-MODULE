#include "BitcoinExchange.hpp"

bool	checkValidDate(const std::string &date)
{
	std::vector<int> values;
	std::stringstream ss(date);
	std::string item;
	while (std::getline(ss, item, '-'))
		values.push_back(atoi(item.c_str()));
	if (values.size() != 3)
		return (false);
	if (values[0] < YEAR_MIN || values[0] > YEAR_MAX)
		return (false);
	if (values[1] < MONTH_MIN || values[1] > MONTH_MAX)
		return (false);
	if (values[2] < DAY_MIN || values[2] > DAY_MAX)
		return (false);
	return (true);
}
