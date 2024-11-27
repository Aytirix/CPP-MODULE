#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

class FragTrap : public ClapTrap {
public:
	// Constructors and destructors
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);
	virtual ~FragTrap();

	// Functions
	void highFivesGuys() const;
};

#endif