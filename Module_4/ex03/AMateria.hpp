#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <cstdlib>

class AMateria {
public:
	AMateria();
	AMateria(std::string name);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria &other);
	virtual ~AMateria();	

	// Getters and setters
	std::string getType() const { return _type; }
	void setType(std::string type) { _type = type; }

	// Functions
protected:
	std::string _type;
};

#endif