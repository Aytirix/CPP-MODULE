#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#include <iostream>
#include <cstdlib>

class Dog : public Animal {
public:
	// Constructors and destructors
	Dog();
	Dog(std::string name);
	Dog(const Dog& other);
	Dog& operator=(const Dog &other);
	virtual ~Dog();

	// Functions
	void makeSound() const;
private:
	std::string _type;
};

#endif