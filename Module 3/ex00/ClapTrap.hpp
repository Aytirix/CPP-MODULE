#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap {
public:
	// Constructors and destructors
	ClapTrap(std::string name, int lifePoints, int energyPoints, int attackDamage);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	// Getters
	std::string getName();

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