#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#include <iostream>
#include <cstdlib>

class Cat : public Animal {
public:
	// Constructors and destructors
	Cat();
	Cat(std::string name);
	Cat(const Cat& other);
	Cat& operator=(const Cat &other);
	virtual ~Cat();

	// Functions
	void makeSound() const;
private:
	std::string _type;
};

#endif