#include "Zombie.hpp"

int main(void)
{
	Zombie* z1 = newZombie("Zombie one");
	Zombie* z2 = newZombie("Zombie two");

	z1->announce();
	z2->announce();
	delete z1;
	delete z2;

	randomChump("Zombie three temp");

	return 1;
}
