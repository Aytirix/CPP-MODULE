#include "BitcoinExchange.hpp"

bool checkValidDate(const std::string &date)
{
    std::map<std::string, int> dateMap;
    std::map<int, std::string> keys;
    keys[0] = "year";
    keys[1] = "month";
    keys[2] = "day";

    size_t start = 0, end;
    int i = 0;
    while ((end = date.find('-', start)) != std::string::npos && i < 3)
    {
        dateMap[keys[i]] = std::atoi(date.substr(start, end - start).c_str());
        start = end + 1;
        i++;
    }
    if (i < 2) 
        return (false);
    dateMap[keys[i]] = std::atoi(date.substr(start).c_str());

    if (dateMap["year"] < YEAR_MIN || dateMap["year"] > YEAR_MAX)
        return (false);
    if (dateMap["month"] < MONTH_MIN || dateMap["month"] > MONTH_MAX)
        return (false);
    if (dateMap["day"] < DAY_MIN || dateMap["day"] > DAY_MAX)
        return (false);

    return (true);
}
