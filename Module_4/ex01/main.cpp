#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
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
	Animal *animal[10];

	printColor("Creating 5 dogs", "green");
	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
		animal[i]->makeSound();
	}
	printColor("\nCreating 5 cats", "green");
	for (int i = 5; i < 10; i++)
	{
		animal[i] = new Cat();
		animal[i]->makeSound();
	}

	printColor("\nDeleting all animals", "red");
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
	}

	printColor("\nTest IDEAS CAT", "green");
	Cat *cat = new Cat();
	cat->setIdeas(0, "I am a cat");
	cat->setIdeas(1, "I am a cat 2");
	cat->setIdeas(5, "I am a cat 3");
	cat->getIdeas();

	printColor("\nTest copy constructor", "green");
	Cat *cat2 = new Cat(*cat);
	cat2->getIdeas();
	delete cat;
	delete cat2;
	return (0);
}