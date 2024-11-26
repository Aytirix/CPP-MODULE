#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), LifePoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), LifePoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << name << " is created!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignation operator called!" << std::endl;
	this->name = other.name;
	this->LifePoints = other.LifePoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

// Getters
std::string ClapTrap::getName()
{
	return (this->name);
}

// Setters

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

// Functions
bool ClapTrap::CheckConsumer()
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return (false);
	}
	if (this->LifePoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of life!" << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(std::string const &target)
{
	if (CheckConsumer())
	{
		EnergyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (CheckConsumer())
	{
		if (this->LifePoints <= amount)
			this->LifePoints = 0;
		else
			this->LifePoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (CheckConsumer())
	{
		EnergyPoints--;
		LifePoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
	}
}
