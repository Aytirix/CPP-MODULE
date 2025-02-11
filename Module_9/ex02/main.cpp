#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	system("clear");
	if (argc < 2)
	{
		std::cerr << "Error: No numbers provided." << std::endl;
		return (1);
	}

	PmergeMe sorter;
	sorter.parseInput(argc, argv);
	sorter.sortAndMeasure();

	return (0);
}