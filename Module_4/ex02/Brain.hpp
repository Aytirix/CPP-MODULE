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
	std::string getIdea(int i) const;
	const std::string *getIdeasAddress(int i) const;
	void setIdea(int i, std::string ideas);

	// Functions
protected:
	std::string _ideas[100];
};

#endif