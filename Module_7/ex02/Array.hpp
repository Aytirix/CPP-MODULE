#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cmath>
# include <iostream>
# include <string>

template <typename T> class Array
{
  public:
	// Forme canonique
	Array() : _array(NULL), _size(0) {}
	Array(int n)
	{
		if (n > 0)
			_array = new T[n]();
		else if (n == 0)
			_array = NULL;
		else
			throw std::invalid_argument("Array: Negative size (constructor)");
		_size = n;
	}
	inline Array(Array const &src) : _array(NULL), _size(0) { *this = src; }
	inline ~Array() { delete[] _array; }
	Array &operator=(Array const &src)
	{
		if (this != &src)
		{
			delete[] _array;

			_size = src._size;
			if (_size > 0)
			{
				_array = new T[_size]();
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = src._array[i];
			}
			else
				_array = NULL;
		}
		return (*this);
	}

	// Fonctions membres
	inline unsigned int size() const { return _size; }
	inline T &operator[](unsigned int index) 
	{
		if (index >= _size)
			throw std::out_of_range("Array: index out of range");
		return _array[index];
	}

  private:
	T *_array;
	unsigned int _size;
};

#endif