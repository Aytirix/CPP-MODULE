#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <cstdlib>

class ScavTrap {
public:
	// Constructors and destructors
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	// Getters
	std::string getName();

	// Setters
	void setName(std::string name);

	// Functions
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	bool CheckConsumer();
private:
	std::string name;
	unsigned int AttackDamage;
	unsigned int EnergyPoints;
	unsigned int LifePoints;                                                                                                     
};

#endif