#include "Whatever.hpp"


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	system("clear");


	// SWAP
	int a = 55;
	int b = 20;
	std::cout << "SWAP :" << std::endl;
	std::cout << " a = " << a << " | b = " << b << std::endl;
	swap(a, b);
	std::cout << " a = " << a << " | b = " << b << std::endl;

	std::cout << "MIN : " << min(a , b) << std::endl;

	std::cout << "MAX : " << max(a , b) << std::endl;

	std::cout << std::endl;

	std::string str1 = "World !";
	std::string str2 = "Hello ";
	std::cout << "SWAP :" << std::endl;
	std::cout << " a = " << str1 << " | b = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << " a = " << str1 << " | b = " << str2 << std::endl;

	std::cout << "MIN : " << min(str1 , str2) << std::endl;

	std::cout << "MAX : " << max(str1 , str2) << std::endl;
	return (0);
}
