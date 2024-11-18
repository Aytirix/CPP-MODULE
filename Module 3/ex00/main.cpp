#include "ClapTrap.hpp"

int main(void)
{
	system("clear");

	ClapTrap camille = ClapTrap("Camille", 100, 3, 20);
	ClapTrap spike = ClapTrap("Spike", 50, 3, 20);

	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.attack(spike.getName());
	camille.beRepaired(10);


	std::cout << std::endl << std::endl << std::endl;

	return 0;
}
