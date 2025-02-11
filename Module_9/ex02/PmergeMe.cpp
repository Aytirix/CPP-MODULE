#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <utility>

// Forme canonique

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector),
	_deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

// Functions

void PmergeMe::parseInput(int argc, char **argv)
{
	int	i;
	int	num;

	for (i = 1; i < argc; i++)
	{
		num = std::atoi(argv[i]);
		if (num <= 0)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		if (std::find(_vector.begin(), _vector.end(), num) != _vector.end())
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

void PmergeMe::sortAndMeasure()
{
	clock_t start, end;
	double vectorTime, dequeTime;
	std::vector<int> unsorted = _vector;

	std::vector<std::pair<int, int> > pairs_vector;
	std::deque<std::pair<int, int> > pairs_deque;
	std::vector<int> leftovers_vector;
	std::deque<int> leftovers_deque;
	CreatePairs(_vector, pairs_vector, leftovers_vector);
	CreatePairs(_vector, pairs_deque, leftovers_deque);

	// test for Vector
	start = clock();
	mergeInsertSort(_vector, pairs_vector, leftovers_vector);
	end = clock();
	vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	// test for Deque
	start = clock();
	mergeInsertSort(_deque, pairs_deque, leftovers_deque);
	end = clock();
	dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	printResults(unsorted, vectorTime, dequeTime);
}

void PmergeMe::printResults(const std::vector<int> &original, double vectorTime,
	double dequeTime)
{
	size_t	i;

	std::cout << "Before: ";
	for (i = 0; i < original.size() && i < NUMBER_PRINT; i++)
		std::cout << original[i] << " ";
	if (original.size() > NUMBER_PRINT)
		std::cout << "[...]";
	std::cout << std::endl;
	std::cout << "After: ";
	for (i = 0; i < _vector.size() && i < NUMBER_PRINT; i++)
		std::cout << _vector[i] << " ";
	if (_vector.size() > NUMBER_PRINT)
		std::cout << "[...]";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
