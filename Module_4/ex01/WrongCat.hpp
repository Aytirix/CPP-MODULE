#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <iostream>
#include <cstdlib>

class WrongCat : public WrongAnimal {
public:
	// Constructors and destructors
	WrongCat();
	WrongCat(std::string name);
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat &other);
	virtual ~WrongCat();

	// Functions
	void makeSound() const;
private:
	std::string _type;
};

#endif