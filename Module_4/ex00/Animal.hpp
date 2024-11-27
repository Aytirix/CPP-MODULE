#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
public:
	virtual ~Animal();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
	virtual void makeSound() const = 0; 
protected:
	Animal();
	Animal(std::string name);
	Animal(const Animal& other);
	Animal& operator=(const Animal &other);

private:
	std::string _type;
};

#endif