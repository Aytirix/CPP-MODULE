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



	printColor("\nTest 3: Cat", "blue");
	Cat *cat = new Cat();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->setIdeas(0, "I am a cat");
	cat->setIdeas(3, "I am not a dog");
	cat->setIdeas(8, "I am not a human");
	cat->setIdeas(9, "I am a cat");
	cat->setIdeas(555, "I am not a non binary");
	cat->setIdeas(55, "I am not a non binary");
	cat->getIdeas();
	cat->makeSound();
	delete cat;

	printColor("\nTest 4: Dog", "green");
	Dog *dog = new Dog();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	dog->setIdeas(2, "I am a dog");
	dog->setIdeas(0, "I am not a cat");
	dog->setIdeas(-1, "I am not a human");
	dog->setIdeas(99, "I am a dog");
	dog->setIdeas(745, "I am not a non binary");
	dog->setIdeas(99, "I am not a non binary");
	dog->getIdeas();
	Dog *dog2 = new Dog(*dog);
	delete dog;

	printColor("\nTest 4: Dog", "green");
	dog2->setIdeas(0, "copy dog");
	dog2->setIdeas(99, "");
	dog2->getIdeas();
	delete dog2;
	return 0;
}
