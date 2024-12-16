#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int	main(void)
{
	system("clear");

	Animal *animal[10];

	std::cout << GREEN REVERSE "Creating 5 dogs" RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
		animal[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << GREEN REVERSE "\nCreating 5 cats" RESET << std::endl;
	for (int i = 5; i < 10; i++)
	{
		animal[i] = new Cat();
		animal[i]->makeSound();
		std::cout << std::endl;
	}

	std::cout << RED REVERSE "\nDeleting all animals" RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
		std::cout << std::endl;
	}

	// Test 1: Animal
	std::cout << YELLOW REVERSE "\nTest 1: Animal" RESET << std::endl;
	const Animal *meta = new Animal();
	const Animal *meta2 = new Animal(*meta);
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	meta2->makeSound();
	delete meta;
	delete meta2;

	// Test 2: Dog
	std::cout << GREEN REVERSE "\nTest 2: Dog" RESET << std::endl;
	const Animal *dog = new Dog();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;

	// Test 3: Cat
	std::cout << BLUE REVERSE "\nTest 3: Cat" RESET << std::endl;
	const Animal *cat = new Cat();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;

	// Test 4: WrongAnimal
	std::cout << MAGENTA REVERSE "\nTest 4: WrongAnimal" RESET << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;

	// Test 5: WrongCat
	std::cout << CYAN REVERSE "\nTest 5: WrongCat" RESET << std::endl;
	const WrongCat *wrongCat = new WrongCat();
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;

	return (0);
}