#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal &other);
	virtual ~WrongAnimal();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif