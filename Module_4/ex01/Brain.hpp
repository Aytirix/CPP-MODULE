#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <cstdlib>

class Brain {
public:
	Brain();
	Brain(std::string name);
	Brain(const Brain& other);
	Brain& operator=(const Brain &other);
	virtual ~Brain();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif