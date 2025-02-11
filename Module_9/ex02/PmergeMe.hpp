#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
# include <cmath>

#define NUMBER_PRINT 5

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(int argc, char **argv);
    void sortAndMeasure();
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    
	void printResults(const std::vector<int>& original, double vectorTime, double dequeTime);

	template <typename Container, typename Pairs, typename Leftovers>
	void CreatePairs(Container &array, Pairs &pair, Leftovers &leftover);

	template <typename Container, typename Pairs, typename Leftovers>
	void mergeInsertSort(Container &array, Pairs &pairs, Leftovers &leftovers);
};

#include "PmergeMe.tpp"

#endif
