#include "RPN.hpp"

int	main(int ac, char **av)
{
	system("clear");
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <Expression>" << std::endl;
		return (1);
	}
	RPN rpn;
	if (!rpn.calculate(av[1]))
		return (1);
	return (0);
}
