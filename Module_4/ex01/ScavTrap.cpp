#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	LifePoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	LifePoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << name << " copied!" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignation operator called!" << std::endl;
	this->name = other.name;
	this->LifePoints = other.LifePoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
}