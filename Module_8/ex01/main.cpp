#include "Span.hpp"
#include <sstream>
#include <vector>

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------------" << std::endl;
	Span sp2 = Span(10000);
	std::vector<int> numbers;
	for (int i = 0; i < 10000; ++i)
	{
		numbers.push_back(i);
	}
	sp2.addNumbers(numbers.begin(), numbers.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return (0);
}
