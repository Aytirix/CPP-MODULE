#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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

	void getIdeas(void) const;
	void setIdeas(int i, std::string ideas);

	// Functions
	void makeSound() const;
private:
	std::string _type;
	Brain *_brain;
};

#endif