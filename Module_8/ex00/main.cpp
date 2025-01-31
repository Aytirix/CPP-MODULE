#include "easyfind.hpp"
#include <vector>
#include <sstream>

int str_to_int(std::string str)
{
	std::stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

int main(int ac, char **av)
{
	system("clear");

	if (ac != 3)
	{
		std::cout << "Usage: ./easyfind <n1,n2,n3,n4> <number>" << std::endl;
		return (1);
	}

	std::string find = av[2];
	if (find.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Second argument must be a number '" << av[2] << "'" << std::endl;
		return (1);
	}

	int n = str_to_int(av[2]);
	std::string str = av[1];
	std::stringstream ss(str);
	std::vector<int> v;
	while (ss.good())
	{
		std::string substr;
		getline(ss, substr, ',');
		if (substr.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "First argument must be a list of numbers separated by commas '" << substr << "'" << std::endl;
			return (1);
		}
		v.push_back(str_to_int(substr));
	}

	try
	{
		std::cout << easyfind(v, n) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}
