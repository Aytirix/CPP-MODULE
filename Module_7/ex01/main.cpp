#include "iter.hpp"

void increment(int &i)
{
	i++;
}

void print(int &i)
{
	std::cout << i << std::endl;
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	system("clear");


	std::cout << "iter :" << std::endl;
	int tab[] = {1, 2, 3, 4, 5};
	iter(tab, 5, print);
	iter(tab, 5, increment);
	std::cout << std::endl;
	iter(tab, 5, print);

	return (0);
}
