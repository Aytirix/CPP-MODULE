#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Colors.hpp"
#include <map>

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

	std::cout << YELLOW REVERSE "\nTest IDEAS CAT" RESET << std::endl;
	Cat *cat = new Cat();
	cat->setIdeas(0, "I am a cat");
	cat->setIdeas(1, "I am a cat 2");
	cat->setIdeas(5, "I am a cat 3");
	std::cout << std::endl;
	cat->getIdeas();

	std::cout << GREEN REVERSE "\nTest copy constructor" RESET << std::endl;
	Cat *cat2 = new Cat(*cat);
	std::cout << std::endl;
	cat2->getIdeas();
	std::cout << RED "\nDeleting cat" RESET << std::endl;
	delete cat;
	std::cout << RED "\nDeleting cat2" RESET << std::endl;
	delete cat2;

	std::cout << YELLOW REVERSE "\nTest IDEAS DOG" RESET << std::endl;
	Dog *dog = new Dog();
	dog->setIdeas(0, "I am a dog");
	dog->setIdeas(1, "I am a dog 2");
	dog->setIdeas(5, "I am a dog 3");
	std::cout << std::endl;
	dog->getIdeas();

	std::cout << GREEN REVERSE "\nTest copy constructor" RESET << std::endl;
	Dog *dog2 = new Dog(*dog);
	std::cout << std::endl;
	dog2->getIdeas();
	std::cout << RED "\nDeleting dog" RESET << std::endl;
	delete dog;
	std::cout << RED "\nDeleting dog2" RESET << std::endl;
	delete dog2;
	return (0);
}
