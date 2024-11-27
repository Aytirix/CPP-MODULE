#include "ClapTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Camille");
	ClapTrap spike = ClapTrap("Spike");

	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.beRepaired(10);

	spike.takeDamage(9);
	spike.beRepaired(10);
	spike.takeDamage(100);
	spike.takeDamage(100);
	return 0;
}
