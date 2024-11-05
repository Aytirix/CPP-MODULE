#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; ++i)
		{
			for (std::size_t j = 0; j < std::strlen(av[i]); ++j)
			{
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
	}
	std::cout << "\n";
}