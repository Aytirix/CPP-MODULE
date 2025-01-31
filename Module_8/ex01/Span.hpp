#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <cmath>
# include <iostream>
# include <string>
# include <vector>

class Span
{
  private:
	std::vector<int> _v;
	unsigned int _n;

  public:
	// Constructors form canonical form
	Span(unsigned int n) : _n(n) {}
	Span(const Span &other) : _v(other._v), _n(other._n) {}
	Span &operator=(const Span &other)
	{
		if (this != &other)
		{
			_v = other._v;
			_n = other._n;
		}
		return (*this);
	}
	~Span() {}

	void addNumber(int n)
	{
		if (_v.size() >= _n)
			throw std::runtime_error("Max number of elements reached");
		_v.push_back(n);
	}

	int shortestSpan()
	{
		if (_v.size() <= 1)
			throw std::runtime_error("Not enough elements");
		std::vector<int> v = _v;
		std::sort(v.begin(), v.end());
		int min = std::abs(v[0] - v[1]);
		for (unsigned int i = 1; i < v.size() - 1; i++)
		{
			int diff = std::abs(v[i] - v[i + 1]);
			if (diff < min)
				min = diff;
		}
		return (min);
	}

	int longestSpan()
	{
		if (_v.size() <= 1)
			throw std::runtime_error("Not enough elements");
		std::vector<int> v = _v;
		std::sort(v.begin(), v.end());
		return (std::abs(v[0] - v[v.size() - 1]));
	}

	template <typename InputIterator> void addNumbers(InputIterator begin,
		InputIterator end)
	{
		if (_v.size() + std::distance(begin, end) > _n)
			throw std::runtime_error("Max number of elements reached");
		_v.insert(_v.end(), begin, end);
	}
};

#endif