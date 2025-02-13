#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <deque>
# include <vector>
# include <iostream>
# include <iomanip>
# include <algorithm>

# define NUMBER_PRINT 100000

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseInput(int argc, char **argv);
	void sortAndMeasure();

  private:
	std::vector<int> _vector;
	std::deque<int> _deque;

	void printResults(const std::vector<int> &original, double vectorTime,
		double dequeTime);

	template <typename Container, typename Pairs, typename Leftovers>
	void CreatePairs(Container &array, Pairs &pair, Leftovers &leftover);

	template <typename Container, typename Pairs, typename Leftovers>
	void Sort_Ford_Johnson(Container &array, Pairs &pairs, Leftovers &leftovers);

	template <typename Container>
	void insert_Jacobsthon_Recursif(Container &sortedArray, Container &elements, size_t left, size_t right);

	template <typename Container>
	void mergeSort(Container &arr, size_t left, size_t right);

	template <typename Container>
	void merge(Container &arr, size_t left, size_t mid, size_t right);
};

# include "PmergeMe.tpp"

#endif
