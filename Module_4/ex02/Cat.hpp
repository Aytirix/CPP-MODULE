#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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

	void getIdeas(void) const;
	void setIdeas(int i, std::string ideas);

	// Functions
	void makeSound() const;
private:
	Brain *_brain;
};

#endif