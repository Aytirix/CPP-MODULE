	#ifndef EASYFIND_HPP
	# define EASYFIND_HPP

	# include <cmath>
	# include <exception>
	# include <iostream>
	# include <string>
	# include <algorithm>

	template <typename T>
	int easyfind(T &container, int n)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), n);
		if (it == container.end())
			throw std::exception();
		return *it;
	}

	#endif