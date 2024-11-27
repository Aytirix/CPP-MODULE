#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap {
public:
	// Constructors and destructors
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();

	// Getters
	std::string getName();

	// Setters
	void setName(std::string name);

	// Functions
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	bool CheckConsumer();

protected:
	std::string name;
	unsigned int LifePoints;                                                                                                     
	unsigned int EnergyPoints;
	unsigned int AttackDamage;
};

#endif