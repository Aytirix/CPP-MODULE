#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Camille");
	ScavTrap other = ScavTrap("Other");

	camille.attack("Spike");
	camille.attack("Spike");
	camille.beRepaired(10);
	camille.takeDamage(100);
	camille.takeDamage(100);

	other.attack("Camille");
	other.attack("Camille");
	other.takeDamage(50);
	other.takeDamage(10);
	return 0;
}
