#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace <filename> <string to replace> <string to replace with>" << std::endl;
		return 1;
	}
	Replace r;
	r.replace(av[1], av[2], av[3]);
	return 0;
}