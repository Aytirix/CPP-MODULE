#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Clap");
	camille.attack("Spike");
	camille.attack("Spike");
	camille.beRepaired(10);
	camille.takeDamage(100);
	camille.takeDamage(100);

	std::cout << std::endl;

	ScavTrap scav = ScavTrap("Scav");
	scav.attack("Camille");
	scav.attack("Camille");
	scav.takeDamage(50);
	scav.takeDamage(10);
	scav.guardGate();

	std::cout << std::endl;

	FragTrap frag = FragTrap("Frag");
	frag.attack("Camille");
	frag.attack("Camille");
	frag.takeDamage(50);
	frag.takeDamage(10);
	frag.highFivesGuys();
	return 0;
}
