#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
public:
	Animal();
	Animal(std::string name);
	Animal(const Animal& other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif