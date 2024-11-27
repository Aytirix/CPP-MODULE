#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Clap");
	ScavTrap scav = ScavTrap("Scav");
	FragTrap frag = FragTrap("Frag");

	camille.attack("Spike");
	camille.attack("Spike");
	camille.beRepaired(10);
	camille.takeDamage(100);
	camille.takeDamage(100);

	scav.attack("Camille");
	scav.attack("Camille");
	scav.takeDamage(50);
	scav.takeDamage(10);
	scav.guardGate();

	frag.attack("Camille");
	frag.attack("Camille");
	frag.takeDamage(50);
	frag.takeDamage(10);
	return 0;
}
