#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(4, "Zombie horde");
	for (int i = 0; i < 4; i++)
		horde[i].announce();
	delete[] horde;
	return 1;
}
