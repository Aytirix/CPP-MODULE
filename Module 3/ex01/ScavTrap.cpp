#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "Default";
	this->LifePoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "ScavTrap " << name << " copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}
