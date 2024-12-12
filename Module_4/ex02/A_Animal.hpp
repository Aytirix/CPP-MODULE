#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class A_Animal {
public:
	A_Animal();
	A_Animal(std::string name);
	A_Animal(const A_Animal& other);
	A_Animal& operator=(const A_Animal &other);
	virtual ~A_Animal();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
	virtual void makeSound() const = 0;
protected:
	std::string _type;
};

#endif