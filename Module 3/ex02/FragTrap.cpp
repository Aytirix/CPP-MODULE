#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	LifePoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " is created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	LifePoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " is created!" << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << name << " copied!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignation operator called!" << std::endl;
	this->name = other.name;
	this->LifePoints = other.LifePoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap " << this->name << " You want a high five?" << std::endl;
}