#ifndef ITER_HPP
# define ITER_HPP

# include <cmath>
# include <iostream>
#include <string>

template<typename T>
void iter(T *tab, int size, void (*f)(T &))
{
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

#endif