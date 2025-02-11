#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <utility>

template <typename Container, typename Pairs, typename Leftovers>
void PmergeMe::CreatePairs(Container &array, Pairs &pair, Leftovers &leftover)
{
	size_t	i;

	for (i = 0; i + 1 < array.size(); i += 2)
	{
		if (array[i] > array[i + 1])
			pair.push_back(std::make_pair(array[i + 1], array[i]));
		else
			pair.push_back(std::make_pair(array[i], array[i + 1]));
	}
	if (array.size() % 2 != 0)
		leftover.push_back(array[array.size() - 1]);
}

// Algorithm Ford-Johnson

template <typename Container, typename Pairs, typename Leftovers>
void PmergeMe::mergeInsertSort(Container &array, Pairs &pairs, Leftovers &leftovers)
{
	(void)array;
	(void)pairs;
	(void)leftovers;

	if (array.size() <= 1)
		return ;

}
