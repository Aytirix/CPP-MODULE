#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	system("clear");
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Usage: ./bitcoin_exchange <filename>" << std::endl;
		return (1);
	}
	BitcoinExchange exchange;
	if (!exchange.loadData("data.csv"))
		return (1);
	exchange.CheckInputUser(av[1]);
	return (0);
}