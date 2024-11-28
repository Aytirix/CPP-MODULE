#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// Fonction pour afficher du texte en couleur
void printColor(const std::string& text, int color)
{
	std::cout << "\033[1;" << color << "m \n" << text << "\033[0m";
}

int main()
{
	// Test 1: Animal
	printColor("Test 1: Animal\n", 33);
	const Animal* meta = new Animal();
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;

	// Test 2: Dog
	printColor("Test 2: Dog\n", 34);
	const Animal* dog = new Dog();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;

	// Test 3: Cat
	printColor("Test 3: Cat\n", 35);
	const Animal* cat = new Cat();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;

	// Test 4: WrongAnimal
	printColor("Test 4: WrongAnimal\n", 36);
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;

	// Test 5: WrongCat
	printColor("Test 5: WrongCat\n", 31);
	const WrongCat* wrongCat = new WrongCat();
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;

	return 0;
}