#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <map>

void	printColor(const std::string &text, std::string color)
{
	std::map<std::string, std::string> colorMap;
	colorMap["black"] = "30";
	colorMap["red"] = "31";
	colorMap["green"] = "32";
	colorMap["yellow"] = "33";
	colorMap["blue"] = "34";
	colorMap["magenta"] = "35";
	colorMap["cyan"] = "36";
	colorMap["white"] = "37";
	std::map<std::string, std::string>::iterator it = colorMap.find(color);
	if (it != colorMap.end())
		color = it->second;
	else
		color = "37";
	std::cout << "\033[1;" << color << "m" << text << "\033[0m" << std::endl;
}

int	main(void)
{
	system("clear");
	// Test 1: Animal
	printColor("Test 1: Animal", "yellow");
	const Animal *meta = new Animal();
	const Animal *meta2 = new Animal(*meta);
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	meta2->makeSound();
	delete meta;
	delete meta2;

	// Test 2: Dog
	printColor("\nTest 2: Dog", "green");
	const Animal *dog = new Dog();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;

	// Test 3: Cat
	printColor("\nTest 3: Cat", "blue");
	const Animal *cat = new Cat();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;

	// Test 4: WrongAnimal
	printColor("\nTest 4: WrongAnimal", "magenta");
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;

	// Test 5: WrongCat
	printColor("\nTest 5: WrongCat", "cyan");
	const WrongCat *wrongCat = new WrongCat();
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;

	return (0);
}