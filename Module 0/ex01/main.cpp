#include "PhoneBook.hpp"

void Space(size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << " ";
}

int main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << "Le programme ne prend pas d'arguments." << std::endl;
		return 1;
	}
	PhoneBook pb;
	pb.start();
	return 0;
}