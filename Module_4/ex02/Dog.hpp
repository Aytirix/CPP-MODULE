#ifndef DOG_HPP
#define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <cstdlib>

class Dog : public A_Animal {
public:
	// Constructors and destructors
	Dog();
	Dog(std::string name);
	Dog(const Dog& other);
	Dog& operator=(const Dog &other);
	virtual ~Dog();

	void getIdeas(void) const;
	void setIdeas(int i, std::string ideas);
	void getBrain(void) const;
	Brain *getBrain(void);

	// Functions
	void makeSound() const;
private:
	Brain *_brain;
};

#endif