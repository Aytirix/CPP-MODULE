#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Colors.hpp"
#include "Data.hpp"
# include <iostream>
# include <cmath>

class Serializer
{
  public:
	// Getters and setters

	// Exceptions

	// Functions	
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
  private:
	// Constructors and destructors
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

};

// Operators

#endif