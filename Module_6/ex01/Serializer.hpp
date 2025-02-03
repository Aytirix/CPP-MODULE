#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Colors.hpp"
#include "Data.hpp"
# include <iostream>
# include <cmath>
#include <stdint.h>

class Serializer
{
  public:
	// Getters and setters

	// Exceptions

	// Functions	
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
  private:
	// Constructors and destructors
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

};

// Operators

#endif