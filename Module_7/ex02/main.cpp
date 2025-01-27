#include "Array.hpp"

int	main(void)
{
	system("clear");

	// Constructeur par défaut
	std::cout << "\nTest constructeur par défaut" << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	// Contructeur avec un paramètre
	std::cout << "\nTest constructeur avec un paramètre" << std::endl;
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// test constructeur de copie
	std::cout << "\nTest constructeur de copie" << std::endl;
	Array<int> original(3);
	original[0] = 10;
	original[1] = 20;
	original[2] = 30;

	Array<int> copy = original;
	copy[0] = 50;
	copy[0] = 60;
	copy[0] = 70;

	std::cout << "Original : ";
	for (unsigned int i = 0; i < original.size(); ++i)
		std::cout << original[i] << " ";
	std::cout << std::endl;

	std::cout << "Copy     : ";
	for (unsigned int i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	// test opérateur d'affectation
	std::cout << "\nTest opérateur d'affectation" << std::endl;
	Array<int> array1(3);
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;

	Array<int> array2;
	array2 = array1;

	array2[1] = 42;

	std::cout << "Array1: ";
	for (unsigned int i = 0; i < array1.size(); ++i)
		std::cout << array1[i] << " ";
	std::cout << std::endl;

	std::cout << "Array2: ";
	for (unsigned int i = 0; i < array2.size(); ++i)
		std::cout << array2[i] << " ";
	std::cout << std::endl;

	// Exception
	std::cout << "\nTest exception (index out of range)" << std::endl;
	try
	{
		Array<int> array(3);
		array[3] = 10;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nTest exception construteur (taille négative)" << std::endl;
	try
	{
		Array<int> array(-3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test avec des strings
	std::cout << "\nTest avec des strings" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	for (unsigned int i = 0; i < strArray.size(); ++i) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	return (0);
}