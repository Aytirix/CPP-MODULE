#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <cmath>
# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	// Constructors form canonical form
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			std::stack<T>::operator=(other);
		}
		return (*this);
	}
	~MutantStack() {}

	// Iterator
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}
	iterator end()
	{
		return (std::stack<T>::c.end());
	}

	// Const iterator
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator end() const
	{
		return (std::stack<T>::c.end());
	}

	// Reverse iterator
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend()
	{
		return (std::stack<T>::c.rend());
	}

	// Const reverse iterator
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const
	{
		return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator rend() const
	{
		return (std::stack<T>::c.rend());
	}
};

#endif