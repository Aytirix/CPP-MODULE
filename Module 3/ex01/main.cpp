#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Camille");
	ScavTrap Scav = ScavTrap("Scav");

	camille.attack("Spike");
	camille.attack("Spike");
	camille.beRepaired(10);
	camille.takeDamage(100);
	camille.takeDamage(100);

	Scav.attack("Camille");
	Scav.attack("Camille");
	Scav.takeDamage(50);
	Scav.takeDamage(10);
	Scav.guardGate();
	return 0;
}
